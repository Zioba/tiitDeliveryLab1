class Vertex:
    def __init__(self, value, adj=None):
        self.value = value
        self.adj = []
        if adj is not None:
            self.adj.append(adj)

    def __repr__(self):
        return "%s:%s" % (self.value, self.adj)


def find_vertex(_list, _input_id):
    for _i in _list:
        if _input_id == _i.value:
            return True
    return False


def get_vertex_index(_list, _input_id):
    for _i in _list:
        if _input_id == _i.value:
            return _list.index(_i)
    return None


def add_vertex(_list, _input_value, _input_id):
    if find_vertex(_list, _input_value):
        return False
    if len(_list) == 0:
        _list.append(Vertex(_input_value))
    elif len(_list) == 1:
        _list[0].adj.append(_input_value)
        _list.append(Vertex(_input_value, _list[0].value))
    else:
        for _i in _list:
            if _input_id == _i.value:
                _list[_list.index(_i)].adj.append(_input_value)
                _list.append(Vertex(_input_value, _input_id))
                break
            elif _list.index(_i) == len(_list) - 1:
                return False
    return True


def add_vertex_to_top(_list, _input_value):
    if find_vertex(_list, _input_value):
        return False
    if len(_list) == 0:
        _list.append(Vertex(_input_value))
    else:
        _list[len(_list) - 1].adj.append(_input_value)
        _list.append(Vertex(_input_value, _list[len(_list) - 1].value))
    return True


def delete_vertex(_list, _input_id):
    if len(_list) == 0:
        return False
    for _i in _list:
        if _input_id == _i.value:
            for _j in _list[_list.index(_i)].adj:
                for _k in _list:
                    if _k.value == _j:
                        _list[_list.index(_k)].adj.remove(_input_id)
            del _list[_list.index(_i)]
            break
        elif _list.index(_i) == len(_list) - 1:
            return False
    return True


def insert_link(_list, _input_id, _input_id_2):
    if not find_vertex(_list, _input_id):
        return False
    if not find_vertex(_list, _input_id_2):
        return False
    if _input_id in _list[get_vertex_index(_list, _input_id_2)].adj:
        return False
    if _input_id_2 in _list[get_vertex_index(_list, _input_id)].adj:
        return False
    _list[get_vertex_index(_list, _input_id)].adj.append(_input_id_2)
    _list[get_vertex_index(_list, _input_id_2)].adj.append(_input_id)
    return True


def deep_first_search(_list, _start, _visited):
    _visited.append(_start.value)
    for u in _start.adj:
        if u not in _visited:
            deep_first_search(_list, _list[get_vertex_index(_list, u)], _visited)
