def rule(val, list_in):
    sum_list = 0
    for i in list_in:
        sum_list += i
    if val == 1:
        if sum_list == 2 or sum_list == 3:
            return 1
        else:
            return 0
    else:
        if sum_list == 3:
            return 1
        else:
            return 0