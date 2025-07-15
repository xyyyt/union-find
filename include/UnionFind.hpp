#ifndef UNION_FIND_HPP_
# define UNION_FIND_HPP_

# include <unordered_map>

namespace container
{
    template <typename T>
    class NaiveUnionFind
    {
    public :
        // MakeSet
        NaiveUnionFind(std::initializer_list<T> initList)
        {
            for (const auto& v : initList)
            {
                auto res = _vertices.emplace(v, nullptr);

                if (res.second)
                {
                    res.first->second = &res.first->first;
                }
            }
        }

        [[nodiscard]]
        const T *find(const T& value) const
        {
            auto it = _vertices.find(value);

            if (it == _vertices.cend())
            {
                return nullptr;
            }
            else if (&it->first == it->second)
            {
                return it->second;
            }
            else
            {
                return find(*it->second);
            }
        }

        [[nodiscard]]
        bool Union(const T& value, const T& value2)
        {
            const auto *root = find(value);
            const auto *root2 = find(value2);

            if (!root || !root2 || root == root2)
            {
                return false;
            }

            _vertices[*root] = root2;

            return true;
        }

        template <typename Visitor>
        inline void visit(Visitor visitor) const noexcept(
            noexcept(visitor(_vertices)))
        {
            visitor(_vertices);
        }

    private :
        std::unordered_map<T, const T *> _vertices;
    };

    template <typename T>
    class UnionFindByRank
    {
    public :
        // MakeSet
        UnionFindByRank(std::initializer_list<T> initList)
        {
            for (const auto& v : initList)
            {
                auto res = _vertices.emplace(v, nullptr);

                if (res.second)
                {
                    res.first->second = &res.first->first;
                    _ranks.emplace(&res.first->first, 0);
                }
            }
        }

        [[nodiscard]]
        const T *find(const T& value)
        {
            auto it = _vertices.find(value);

            if (it == _vertices.cend())
            {
                return nullptr;
            }
            else if (&it->first == it->second)
            {
                return it->second;
            }

            const T *root = find(*it->second);

            // Path compression
            _vertices[value] = root;

            return root;
        }

        [[nodiscard]]
        bool Union(const T& value, const T& value2)
        {
            const auto *root = find(value);
            const auto *root2 = find(value2);

            if (!root || !root2 || root == root2)
            {
                return false;
            }

            if (_ranks[root] >= _ranks[root2])
            {
                _vertices[*root2] = root;

                if (_ranks[root] == _ranks[root2])
                {
                    ++_ranks[root];
                }
            }
            else
            {
                _vertices[*root] = root2;
            }

            return true;
        }

        template <typename Visitor>
        inline void visit(Visitor visitor) const noexcept(
            noexcept(visitor(_vertices, _ranks)))
        {
            visitor(_vertices, _ranks);
        }

    private :
        std::unordered_map<T, const T *> _vertices;
        std::unordered_map<const T *, int> _ranks;
    };

    template <typename T>
    class UnionFindBySize
    {
    public :
        // MakeSet
        UnionFindBySize(std::initializer_list<T> initList)
        {
            for (const auto& v : initList)
            {
                auto res = _vertices.emplace(v, nullptr);

                if (res.second)
                {
                    res.first->second = &res.first->first;
                    _sizes.emplace(&res.first->first, 1);
                }
            }
        }

        [[nodiscard]]
        const T *find(const T& value)
        {
            auto it = _vertices.find(value);

            if (it == _vertices.cend())
            {
                return nullptr;
            }
            else if (&it->first == it->second)
            {
                return it->second;
            }

            const T *root = find(*it->second);

            // Path compression
            _vertices[value] = root;

            return root;
        }

        [[nodiscard]]
        bool Union(const T& value, const T& value2)
        {
            const auto *root = find(value);
            const auto *root2 = find(value2);

            if (!root || !root2 || root == root2)
            {
                return false;
            }

            if (_sizes[root] >= _sizes[root2])
            {
                _vertices[*root2] = root;

                if (_sizes[root] == _sizes[root2])
                {
                    _sizes[root] += _sizes[root2];
                }
            }
            else
            {
                _vertices[*root] = root2;
            }

            return true;
        }

        template <typename Visitor>
        inline void visit(Visitor visitor) const noexcept(
            noexcept(visitor(_vertices, _sizes)))
        {
            visitor(_vertices, _sizes);
        }

    private :
        std::unordered_map<T, const T *> _vertices;
        std::unordered_map<const T *, int> _sizes;
    };
}

#endif
