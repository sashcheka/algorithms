n = int(input())
dupa = {}
for _ in range(n):
    s = input().strip()
    if s.startswith("List "):
        left, right = s.split("=", 1)
        list_name = left[5:].strip()
        right = right.strip()
        if "new List(" in right:
            arr_str = right[9:-1]
            if arr_str:
                arr = list(map(int, arr_str.split(",")))
            else:
                arr = []
            dupa[list_name] = [arr, 0]
        elif ".subList(" in right:
            dot = right.find(".subList(")
            parent_list = right[:dot]
            from_str, to_str = right[dot + 9:-1].split(",")
            _from, _to = int(from_str), int(to_str)
            parent_arr, parent_offset = dupa[parent_list]
            dupa[list_name] = [parent_arr, parent_offset + _from - 1]
    elif ".get(" in s:
        list_name, arg = s.split(".get(", 1)
        idx = int(arg[:-1])
        arr, offset = dupa[list_name]
        print(arr[offset + idx - 1])
    elif ".set(" in s:
        list_name, arg = s.split(".set(", 1)
        idx_str, x_str = arg[:-1].split(",")
        idx, x = int(idx_str), int(x_str)
        arr, offset = dupa[list_name]
        arr[offset + idx - 1] = x
    elif ".add(" in s:
        list_name, arg = s.split(".add(", 1)
        x = int(arg[:-1])
        arr, offset = dupa[list_name]
        arr.append(x)