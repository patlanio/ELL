////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     StlIndexValueIteratorAdapter.h (types)
//  Authors:  Chuck Jacobs
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace types
{
    //
    // StlIndexValueIterator implementation
    //
    template <typename IteratorType, typename ValueType>
    StlIndexValueIterator<IteratorType, ValueType>::StlIndexValueIterator(const IteratorType& begin, const IteratorType& end) : _begin(begin), _end(end), _index(0)
    {
        SkipZeros();
    }

    template <typename IteratorType, typename ValueType>
    bool StlIndexValueIterator<IteratorType, ValueType>::IsValid() const
    {
        return (_begin != _end);
    }

    template <typename IteratorType, typename ValueType>
    void StlIndexValueIterator<IteratorType, ValueType>::Next()
    {
        ++_begin;
        ++_index;
        SkipZeros();
    }

    template <typename IteratorType, typename ValueType>
    IndexValue StlIndexValueIterator<IteratorType, ValueType>::Get() const
    {
        return IndexValue{ _index, (double)*_begin };
    }

    template <typename IteratorType, typename ValueType>
    void StlIndexValueIterator<IteratorType, ValueType>::SkipZeros()
    {
        while (_begin < _end && *_begin == 0)
        {
            ++_begin;
            ++_index;
        }
    }

    //
    // Convenience function to create iterator
    //
    template <typename ValueType>
    VectorIndexValueIterator<ValueType> inline MakeStlIndexValueIterator(const std::vector<ValueType>& arr)
    {
        return VectorIndexValueIterator<ValueType>(arr.cbegin(), arr.cend());
    }
}