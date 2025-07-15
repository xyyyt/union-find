#include <gtest/gtest.h>

#include "UnionFind.hpp"

using namespace container;

// namespace
// {
// using Element_t = char;

// template <template <typename> typename UnionFind, typename Visitor>
// void commonTest(Visitor visitor)
// {
//     UnionFind uf{'A', 'B', 'C', 'D', 'E', 'F'};

//     std::cout << "-------------------- On MakeSet ------------------------\n";

//     uf.visit(visitor);

//     assert(*uf.find('A') == 'A');
//     assert(*uf.find('B') == 'B');
//     assert(*uf.find('C') == 'C');
//     assert(*uf.find('D') == 'D');
//     assert(*uf.find('E') == 'E');
//     assert(*uf.find('F') == 'F');
//     assert(!uf.find('1'));

//     std::cout << "-------------------- On Find ---------------------------\n";

//     uf.visit(visitor);

//     assert(uf.Union('A', 'B'));
//     assert(uf.Union('C', 'D'));
//     assert(uf.Union('B', 'D'));
//     assert(uf.Union('E', 'F'));
//     assert(!uf.Union('F', 'F'));

//     std::cout << "-------------------- On Union --------------------------\n";

//     uf.visit(visitor);

//     assert(*uf.find('A') == 'A');
//     assert(*uf.find('B') == 'A');
//     assert(*uf.find('C') == 'A');
//     assert(*uf.find('D') == 'A');
//     assert(*uf.find('E') == 'E');
//     assert(*uf.find('F') == 'E');
//     assert(!uf.find('1'));

//     std::cout << "-------------------- On Find ---------------------------\n";

//     uf.visit(visitor);
// }

// void testNaiveUnionFind()
// {
//     std::cout << "-------------- [Test Naive Union-Find] -----------------\n";

//     auto visitor = [](
//         const std::unordered_map<Element_t, const Element_t *>& vertices) -> void
//     {
//         for (const auto& [vertex, parent] : vertices)
//         {
//             std::cout << "vertex : " << vertex << ", parent : ";

//             if (parent)
//             {
//                 std::cout << *parent;
//             }
//             else
//             {
//                 std::cout << nullptr;
//             }

//             std::cout << '\n';
//         }
//     };

//     commonTest<NaiveUnionFind>(visitor);

//     std::cout << '\n';
// }

// void testUnionFindByRank()
// {
//     std::cout << "-------------- [Test Union-Find by rank] ---------------\n";

//     auto visitor = [](
//         const std::unordered_map<Element_t, const Element_t *>& vertices,
//         const std::unordered_map<const Element_t *, int>& ranks) -> void
//     {
//         for (const auto& [vertex, parent] : vertices)
//         {
//             std::cout << "vertex : "
//                       << vertex
//                       << " (rank : "
//                       << ranks.at(&vertex)
//                       << "), parent : ";

//             if (parent)
//             {
//                 std::cout << *parent;
//             }
//             else
//             {
//                 std::cout << nullptr;
//             }

//             std::cout << '\n';
//         }
//     };

//     commonTest<UnionFindByRank>(visitor);

//     std::cout << '\n';
// }

// void testUnionFindBySize()
// {
//     std::cout << "-------------- [Test Union-Find by size] ---------------\n";

//     auto visitor = [](
//         const std::unordered_map<Element_t, const Element_t *>& vertices,
//         const std::unordered_map<const Element_t *, int>& sizes) -> void
//     {
//         for (const auto& [vertex, parent] : vertices)
//         {
//             std::cout << "vertex : "
//                       << vertex
//                       << " (size : "
//                       << sizes.at(&vertex)
//                       << "), parent : ";

//             if (parent)
//             {
//                 std::cout << *parent;
//             }
//             else
//             {
//                 std::cout << nullptr;
//             }

//             std::cout << '\n';
//         }
//     };

//     commonTest<UnionFindBySize>(visitor);

//     std::cout << '\n';
// }
// }

TEST(UnionFind, Test_NaiveUnionFind)
{
    NaiveUnionFind nuf{'A', 'B', 'C', 'D', 'E', 'F'};
    const char *parent = nullptr;

    parent = nuf.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = nuf.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'B');

    parent = nuf.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'C');

    parent = nuf.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = nuf.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');

    parent = nuf.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'F');

    EXPECT_TRUE(nuf.Union('A', 'B'));
    EXPECT_TRUE(nuf.Union('C', 'D'));
    EXPECT_TRUE(nuf.Union('B', 'D'));
    EXPECT_TRUE(nuf.Union('E', 'F'));
    EXPECT_FALSE(nuf.Union('F', 'F'));

    parent = nuf.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = nuf.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = nuf.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = nuf.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = nuf.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'F');

    parent = nuf.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'F');
}

TEST(UnionFind, Test_UnionFindByRank)
{
    UnionFindByRank ufbr{'A', 'B', 'C', 'D', 'E', 'F'};
    const char *parent = nullptr;

    parent = ufbr.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbr.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'B');

    parent = ufbr.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'C');

    parent = ufbr.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = ufbr.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');

    parent = ufbr.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'F');

    EXPECT_TRUE(ufbr.Union('A', 'B'));
    EXPECT_TRUE(ufbr.Union('C', 'D'));
    EXPECT_TRUE(ufbr.Union('B', 'D'));
    EXPECT_TRUE(ufbr.Union('E', 'F'));
    EXPECT_FALSE(ufbr.Union('F', 'F'));

    parent = ufbr.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbr.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbr.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbr.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbr.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');

    parent = ufbr.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');
}

TEST(UnionFind, Test_UnionFindBySize)
{
    UnionFindBySize ufbs{'A', 'B', 'C', 'D', 'E', 'F'};
    const char *parent = nullptr;

    parent = ufbs.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbs.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'B');

    parent = ufbs.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'C');

    parent = ufbs.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'D');

    parent = ufbs.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');

    parent = ufbs.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'F');

    EXPECT_TRUE(ufbs.Union('A', 'B'));
    EXPECT_TRUE(ufbs.Union('C', 'D'));
    EXPECT_TRUE(ufbs.Union('B', 'D'));
    EXPECT_TRUE(ufbs.Union('E', 'F'));
    EXPECT_FALSE(ufbs.Union('F', 'F'));

    parent = ufbs.find('A');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbs.find('B');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbs.find('C');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbs.find('D');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'A');

    parent = ufbs.find('E');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');

    parent = ufbs.find('F');
    ASSERT_TRUE(parent);
    EXPECT_EQ(*parent, 'E');
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
