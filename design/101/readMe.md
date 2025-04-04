---
title: xsre Initial Design Draft
identifier: xsre.design/101.readMe
---

## Abstract
This document outlines the initial design draft for the xsre system, introducing the core components such as Items, Exhibits, Keepers, Finders, Fragments, and Packets, along with the processes like Slicing and Scattering, and the key concepts like Baseline and Agnostic patterns. These components, processes and concepts collectively build the foundation for the xsre system.

Refer to the [Appendix: Revisions](#appendix-revisions) for a summary of updates to this document.

## Contents
- [Core Components and Processes](#core-components-and-processes)
    - [Items and Exhibit](#items-and-exhibit)
    - [Keepers and Finders](#keepers-and-finders)
    - [Fragments](#fragments)
    - [Packets, Slicing and Scattering](#packets-slicing-and-scattering)
        - [Packet](#packet)
        - [Slicing](#slicing)
        - [Scattering](#scattering)
- [Baseline and Agnostic Patterns](#baseline-and-agnostic-patterns)
    - [Baseline](#baseline)
    - [Agnostic Patterns](#agnostic-patterns)
- [Appendix: Revisions](#appendix-revisions)

# Core Components and Processes

## Items and Exhibit
The core objective of the xsre project is to create a system for the storage and retrieval of Items. To facilitate the organization of these Items, an Exhibit serves as a high-level container for logically grouping related Items.

## Keepers and Finders
To manage the storage and retrieval of Items, the xsre system employs two key components: Keepers and Finders.

- Keepers are responsible for handling the access to storage solution. This separation of storage management allows for optimization of storage access, data placement, and storage utilization.

- Finders function as query processors, navigating the hierarchical structure of Exhibit to retrieve the requested Item.

## Fragments
In the xsre system, a Fragment is a basic storage unit supported by the underlying storage solution. It is necessary to ensure that an Item can be represented as a series of such Fragments to facilitate storage and retrieval.

Refer to the [xsre.design/101.core.fragment](./core/fragment.md) for a detailed understanding of Fragments.

## Packets, Slicing and Scattering

### Packet
At the lowest level of storage, Fragments are organized into Packets. The xsre system grants Packets absolute freedom to arrange and rearrange Fragments as required. This flexibility allows for optimizations based on storage characteristics and Item access patterns, such as row-major, column-major, or custom layouts.

Packets may contain metadata describing internal Fragment arrangement, enabling direct retrieval for fast query processing.

### Slicing
The objective of the Slicing process is to partition a larger Packet into smaller Packets based on the characteristics of the underlying storage solution for the purpose of optimizing storage utilization.

### Scattering
The Scattering process involves distributing the Packets across different storage targets. This is particularly useful for scalability and performance optimization.

# Baseline and Agnostic Patterns
The xsre system does not impose any mandates on the implementation of core components or processes, apart from the operational requirements of the system.

## Baseline
For general usability, Baseline provides a set of guidelines pertaining to the implementation of generic interfaces and components. Adherence to these guidelines is not mandatory.

Refer to the [xsre.design/101.baseline.readMe](./baseline/readMe.md) for an overview of the concept and guidelines of the Baseline.

## Agnostic Patterns
The Agnostic patterns, on the other hand, are a set of design patterns intended to be used in conjunction with the Baseline. These patterns facilitate the implementation of Baseline-compliant components and processes.

# Appendix: Revisions

### April 05, 2025: Components, Processes and Concepts
- Refined the structure of the document, introducing sections for core components, processes, and concepts.

### April 03, 2025: Preliminary incomplete public draft
- Introducing key components and processes.
