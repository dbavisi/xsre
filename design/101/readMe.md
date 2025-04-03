---
title: xsre Initial Design Draft
identifier: xsre.design/101.readMe
---

## Abstract
This document outlines the initial design draft for the xsre system, introducing key concepts such as Items, Exhibits, Keepers, Finders, Fragments, and Packets, along with processes like Slicing and Scattering. These components and processes collectively build the foundation for xsre system.

Refer [Appendix: Revisions](#appendix-revisions) for the summary of changes made to this document.

## Contents
- [Items and Exhibit](#items-and-exhibit)
- [Keepers and Finders](#keepers-and-finders)
- [Fragments](#fragments)
- [Packets, Slicing and Scattering](#packets-slicing-and-scattering)
  - [Packet](#packet)
  - [Slicing](#slicing)
  - [Scattering](#scattering)

# Items and Exhibit
The core objective of the xsre project is to create a system for the storage and retrieval of Items. To facilitate the organization of these Items, an Exhibit serves as a high-level container for logically grouping related Items.

# Keepers and Finders
To manage the storage and retrieval of Items, the xsre system employs two key components: Keepers and Finders.

- Keepers are responsible for handling the access to storage solution. This separation of storage management allows for optimization of storage access, data placement, and storage utilization.

- Finders function as query processors, navigating the hierarchical structure of Exhibit to retrieve the requested Item.

# Fragments
In the xsre system, a Fragment is a basic storage unit supported by the underlying storage solution. It is necessary to ensure that an Item can be represented as a series of such Fragments to facilitate storage and retrieval.

Refer to the [xsre.design/101.core.fragment](./core/fragment.md) for a detailed understanding of Fragments.

# Packets, Slicing and Scattering

## Packet
At the lowest level of storage, Fragments are organized into Packets. The xsre system grants Packets absolute freedom to arrange and rearrange Fragments as required. This flexibility allows for optimizations based on storage characteristics and Item access patterns, such as row-major, column-major, or custom layouts.

Packets may contain metadata describing internal Fragment arrangement, enabling direct retrieval for fast query processing.

## Slicing
The objective of the Slicing process is to partition a larger Packet into smaller Packets based on the characteristics of the underlying storage solution for the purpose of optimizing storage utilization.

## Scattering
The Scattering process involves distributing the Packets across different storage targets. This is particularly useful for scalability and performance optimization.

# Appendix: Revisions

### April 03, 2024: Preliminary incomplete public draft
- Add reference to xsre.design/101.core.fragment
- Introducing key components and processes.
