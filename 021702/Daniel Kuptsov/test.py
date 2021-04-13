import unittest
import library


# для запуска отдельного теста нужно написать в терминале: python -m unittest test.TestGraph.test_add_vertex
# чтобы тесты определялись в начале функции должно быть написано test_
class TestGraph(unittest.TestCase):
    def test_add_vertex(self):
        adj_list = []
        self.assertEqual(library.add_vertex(adj_list, 0, 0), True)
        self.assertEqual(library.add_vertex(adj_list, 0, 0), False)
        self.assertEqual(library.add_vertex(adj_list, 1, 0), True)
        self.assertEqual(library.add_vertex(adj_list, 2, -1), False)
        self.assertEqual(library.add_vertex(adj_list, -1, 1), True)
        self.assertEqual(library.add_vertex(adj_list, 2, -1), True)

    def test_add_vertex_to_top(self):
        adj_list = []
        self.assertEqual(library.add_vertex_to_top(adj_list, 0), True)
        self.assertEqual(library.add_vertex_to_top(adj_list, 0), False)

    def test_delete_vertex(self):
        adj_list = []
        library.add_vertex_to_top(adj_list, 0)
        self.assertEqual(library.delete_vertex(adj_list, 0), True)
        self.assertEqual(library.delete_vertex(adj_list, 0), False)

    def test_insert_link(self):
        adj_list = []
        library.add_vertex_to_top(adj_list, 0)
        library.add_vertex_to_top(adj_list, 1)
        library.add_vertex_to_top(adj_list, 2)
        self.assertEqual(library.insert_link(adj_list, 0, 2), True)
        self.assertEqual(library.insert_link(adj_list, 0, 2), False)
        self.assertEqual(library.insert_link(adj_list, 0, 3), False)

    def test_find_vertex(self):
        adj_list = []
        library.add_vertex_to_top(adj_list, 0)
        self.assertEqual(library.find_vertex(adj_list, 0), True)
        self.assertEqual(library.find_vertex(adj_list, 1), False)

    def test_get_vertex_index(self):
        adj_list = []
        library.add_vertex_to_top(adj_list, 0)
        self.assertEqual(library.get_vertex_index(adj_list, 0), 0)
        self.assertEqual(library.get_vertex_index(adj_list, 1), None)

    def test_deep_first_search(self):
        adj_list = []
        visited = []
        library.add_vertex_to_top(adj_list, 0)
        library.add_vertex_to_top(adj_list, 1)
        library.add_vertex_to_top(adj_list, -1)
        library.add_vertex_to_top(adj_list, 2)
        library.deep_first_search(adj_list, adj_list[0], visited)
        self.assertEqual(visited, [0, 1, -1, 2])
        self.assertNotEqual(visited, [0, 1, 2, 3])
