---
title: Understanding Fragments in the xsre System
identifier: xsre.design/101.core.fragment
---

## Abstract
This document provides an overview of Fragments in the xsre system, detailing their characteristics and the Fragments defined in the xsre Baseline. It serves as a foundational reference for understanding how Fragments are utilized within the xsre architecture.

Refer to the [Appendix: Revisions](#appendix-revisions) for a summary of changes made to this document.

## Contents
- [Introduction](#introduction)
- [Characteristics of Fragments](#characteristics-of-fragments)
- [xsre Baseline](#xsre-baseline)
  - [buffer, array and string Fragments](#buffer-array-and-string-fragments)

# Introduction
In the xsre system, a Fragment is a basic storage unit supported by the underlying storage solution. It is necessary to ensure that an Item can be represented as a series of such Fragments to facilitate storage and retrieval.

The xsre system does not impose any restrictions on the definition of a Fragment as long as the Keeper can manage the Fragment.

# Characteristics of Fragments

- Storage: Keeper must be able to store the Fragment in the underlying storage solution.
- Retrieval: Keeper must be able to retrieve the Fragment from the underlying storage solution.
- Modification: Keeper must be able to modify the Fragment in the underlying storage solution.
- Deletion: Keeper must be able to delete the Fragment from the underlying storage solution.

- Serialization: Keeper must be able to serialize the Item into the corresponding Fragments.
- Deserialization: Keeper must be able to deserialize the Fragments into the corresponding Item.

# xsre Baseline
The xsre Baseline provides a set of guidelines for implementation of certain common useful interfaces and components. However, it does not mandate implementation of any such interfaces or components.

The following Fragments are defined in the xsre Baseline:

- xsre.design/101.baseline.fragment.ch
- xsre.design/101.baseline.fragment.i8
- xsre.design/101.baseline.fragment.i16
- xsre.design/101.baseline.fragment.i32
- xsre.design/101.baseline.fragment.i64
- xsre.design/101.baseline.fragment.u8
- xsre.design/101.baseline.fragment.u16
- xsre.design/101.baseline.fragment.u32
- xsre.design/101.baseline.fragment.u64
- xsre.design/101.baseline.fragment.f32
- xsre.design/101.baseline.fragment.f64
- xsre.design/101.baseline.fragment.buffer
- xsre.design/101.baseline.fragment.array
- xsre.design/101.baseline.fragment.string

## buffer, array and string Fragments
Following distinction holds for the buffer, array and string Fragments:

- buffer: A contiguous block of null-terminated data.
- array: A contiguous block of length-prefixed data.
- string: A buffer with a specific encoding.

It is important to note that the xsre Baseline does not specify the unit for the size of the buffer, length-prefix or string encoding entries.

# Appendix: Revisions

## April 03, 2024: Preliminary incomplete public draft
- Introduced the concept of Fragments in the xsre system.
