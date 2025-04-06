---
title: Agnostic Template Specialization in C++
identifier: xsre.design/101.agnostic.spec
---

## Abstract
Objective of this document is to explain the Agnostic Template Specialization pattern in C++, the design intution behind the development of this pattern, and its use cases. This pattern is widely used in the xsre system to provide flexibility and adaptability.

Refer to the [Appendix: Revisions](#appendix-revisions) for a summary of updates to this document.

## Contents
- [Agnostic Template Specialization](#agnostic-template-specialization)
    - [Design Intuition](#design-intuition)
    - [Prototype and Solution](#prototype-and-solution)
    - [Use Cases](#use-cases)
    - [Additional Notes](#additional-notes)
- [Appendix: Revisions](#appendix-revisions)

# Agnostic Template Specialization
The Agnostic Template Specialization pattern provides a mechanism for abstraction to design generic interfaces and classes that can be specialized to different types or behaviors without being explicitly exposed to the underlying implementation details.

This pattern is particularly useful in ways that allow developers to use the same base interface or class everywhere in the codebase, while still inheriting the specific behavior of the derived interface or class when needed.

## Design Intuition
Consider the following base class `Fragment` that serves as the basic storage unit in the xsre system,

```cpp
template <typename T>
class Fragment {
    . . .

    serialize() {
        // Generic serialization logic
    }
}
```

Developers may define derivitions of the `Fragment` class for different use cases, say `CompressedFragment`, for efficient storage and retrieval of data.

```cpp
template <typename T>
class CompressedFragment: public Fragment<T> {
    . . .

    // Additional methods and properties
    compress() {
        // specific compression logic
    }
}
```

However, to utilize the functionality of `CompressedFragment`, developers need to explicitly use the `CompressedFragment` type in their code.

```cpp
template <typename T>
std::string serialize(const T data, const int fragType) {
    switch (fragType) {
        case FragmentType::Image:
            return CompressedFragment<T>(data).serialize(); // Optimized
        case FragmentType::Numeric:
            return Fragment<T>(data).serialize(); // Generic
        default:
            return Fragment<T>(data).serialize(); // Generic
    }
} // Fragment serialization
```

This approach can lead to extensibility issues, as developers need to modify the `serialize` function every time a new derived class is added.

Instead, it could be better if the same `Fragment` base class could be used everywhere in the codebase, and the specialization could be handled internally within the `Fragment` class itself.

```cpp
// Conceptual code

std::string buffer = Fragment<Image>.serialize(image);
// Internally call CompressedFragment<Image>::serialize()

std::string buffer = Fragment<Number>.serialize(32 + i64);
std::string buffer = Fragment<myStruct>.serialize(image);
```

However, this approach is not always feasible, since the instantiation of the `Fragment` class with a specific type will not contain the extended functionality of the derived class `CompressedFragment`.

## Prototype and Solution
A naive approach to solve this problem is to make specialization of the `Fragment` class to extend the Derived class `CompressedFragment`.

> Note: This is a conceptual prototype and not a working code.

```cpp
template <typename T>
class Fragment {
    . . .
};

template <typename T>
class CompressedFragment: public Fragment<T> {
    . . .
    // Additional methods and properties
};

// Template specialization for Image type
template <>
class Fragment<Image>: public CompressedFragment<Image> {
    . . .
};
```

This approach would allow the same `Fragment` class to be used everywhere in the codebase, while still inheriting the specific behavior of the derived class when needed.

```cpp
std::string buffer = Fragment<Image>.serialize(image);
// Fragment<Image> inherits CompressedFragment<Image>

std::string buffer = Fragment<Number>.serialize(32 + i64);
std::string buffer = Fragment<myStruct>.serialize(image);
```

However, the cyclic inheritance prevents the compilation of the code, since the `Fragment<Image>` depends on the `CompressedFragment<Image>` which in turn depends on the `Fragment<Image>`.

To solve this problem, Agnostic Template Specialization pattern was developed.

```cpp
template <typename T, int Spec = 0>
class Fragment {
    . . .
};

template <typename T, int Spec = 0>
class CompressedFragment: public Fragment<T, 1> {
    . . .
    // Additional methods and properties
};

template <>
class Fragment<Image>: public CompressedFragment<Image> {
    . . .
};
```

This simple approach works because the `Fragment<Image>` (`Fragment<Image, 0>`) inherits from `CompressedFragment<Image>` (`CompressedFragment<Image, 0>`) which inherits from `Fragment<Image, 1>`.

## Use Cases
This pattern allows the same keyword `Fragment` to be used everywhere in the codebase, while still inheriting the specific behavior of the derived class when needed.

```cpp
// Calls optimized serialization method
std::string buffer = Fragment<Image>.serialize(image);

// Calls generic serialization method
std::string buffer = Fragment<Number>.serialize(32 + i64);
std::string buffer = Fragment<myStruct>.serialize(image);
```

The pattern is particularly useful for developers to inject specific behavior into the base class without modifying all the dependent code.

```cpp
#include <iostream>

template <typename T, int Spec = 0>
class Fragment {
public:
    void serialize() const {
        std::cout << "Fragment of type: " << typeid(T).name() << " with spec: " << Spec << std::endl;
    }
};

template <typename T, int Spec = 0>
class EncryptedFragment : public Fragment<T, 2> {
public:
    void serialize() const {
        std::cout << "EncryptedFragment of type: " << typeid(T).name() << " with spec: " << Spec << std::endl;

        // Call encryption method
        encrypt();

        // Call the base class serialize method
        Fragment<T, 2>::serialize();
    }

    void encrypt() const { std::cout << "Encrypting fragment of type: " << typeid(T).name() << std::endl; }
};

// Inject encryption functionality to all Fragments
template <typename T>
class Fragment<T, 0> : public EncryptedFragment<T> {
    // Nothing to add here
};

int main() {
    EncryptedFragment<int> encryptedFragment;
    encryptedFragment.serialize(); // Calls EncryptedFragment::serialize()

    Fragment<int> injectedFragment;
    injectedFragment.serialize(); // Calls EncryptedFragment::serialize()

    return 0;
}

/*
** Expected output:
**
EncryptedFragment of type: i with spec: 0
Encrypting fragment of type: i
Fragment of type: i with spec: 2
EncryptedFragment of type: i with spec: 0
Encrypting fragment of type: i
Fragment of type: i with spec: 2
**
*/
```

## Additional Notes
The performance impact of this pattern is expected to be negligible, as it is primarily a compile-time mechanism.

It is important to ensure the Spec values do not overlap, as this could lead to unexpected behavior.

# Appendix: Revisions

### April 05, 2025: Preliminary Incomplete Public Draft
- Initial draft of the Agnostic Template Specialization pattern.
