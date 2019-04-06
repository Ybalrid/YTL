# YTL

[Documentation here!](https://ybalrid.github.io/YTL/Doxygen/html/)

[![Build Status](https://travis-ci.org/Ybalrid/YTL.svg?branch=master)](https://travis-ci.org/Ybalrid/YTL)
[![Build status](https://ci.appveyor.com/api/projects/status/9sidxf2e01m8jq4u?svg=true)](https://ci.appveyor.com/project/Ybalrid/ytl)

Ybalrid Template Library : A playground for some C++ templates that may (or may not) be usefull for anything.

Let's just say that this code comes with no warrenty what so ever, okay? :smile:

## Why?

*Why not?* :wink:

Also, I just wanted to have a place where I can put some code that fixes some of the things that I find mildly annoying while writing C++ code.

And, I'm really far from a *template metaprogramming* expert. So, I'll try to put interesting stuff I find out about here.

## Content:

everything is in the `ytl` namespace. When something will be mentioned that is part of the C++ STL, it will be mentioned with it's namespace name (`std::`)

### ytl_algorithm.hpp

 - `erase_remove(container, element)` : use the erase-remove idiom on the whole container to effectively *delete* the element from the container.
 - `erase_remove_if(container, predicate)` : same as `erase_remove`, but you can specify a predicate in the same way you can do to `std::remove_if`.
 - `print_container(container)` : print a spaces separated list of the content of a container that can be iterated through

### ytl_memory.hpp

 - `observer_ptr<T>` : A dumb smart pointer. A simple non-owning pointer wrapper that is constructible from a smart pointer. Merly a copy of a memory address, without any management of ownership whatsoever.

