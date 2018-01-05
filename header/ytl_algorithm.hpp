#ifndef YTL_ALGORITHM
#define YTL_ALGORITHM

#include <algorithm>

namespace ytl
{
    ///Wrap the erase-remove idiom into a single call
    /// \param container A container
    template <class T, typename E>
        void erase_remove(T& container, const E& element)
        {
            container.erase(
                    std::remove(
                        std::begin(container),
                        std::end(container),
                        element),
                    std::end(container));
        }

    ///Wrap the rease-remove idiom with remove_if into a single call
    /// \param predicate a predicate to pass to remove_if (lambda, function poiner...)
    template <class T, typename P>
        void erase_remove(T& container, P predicate)
        {

            container.erase(
                    std::remove(
                        std::begin(container),
                        std::end(container),
                        predicate),
                    std::end(container));
        }
}

#endif

