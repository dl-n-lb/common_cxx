# matt's common code repo 
## What to expect
This is a collection of common code that I use in my projects to simplify the repetetive parts,
with the aim of producing more expressive code where it matters. That means that the code in
this repository may be ugly, or have bad practices. But I don't care, so long as it allows me to
express my intent in the main programs I write. A vector class needn't be written as though it is
being presented in a gallery, neither does a wrapper around a graphics API. They simply need to 
function, hence that is the primary goal of this code. Functioning, with minimal overhead where 
necessary (for example, command line parsing needn't be fast, but an API wrapper around vulkan 
*should*).

**NOTE**
All simd based functionality relies on `std::experimental::simd` (provided in libstdc++ in versions >=11)

## in each section
To get docs for each thing, visit its section and locate the relevant area(s) of the README.
### types
- aliases for more expressive (shorter) type names (`type_alias.hxx`)
- definitions for a more algebraic vector type (but none of its la-specific functions) (`vecn.hxx`)

### util
- command line argument parser (`cmd_opts.hxx`)


## TODO:
- Add tests (IN PROGRESS)
- Write the LA (IN PROGRESS)
- Write the Vk wrapper
- Write docs for above
