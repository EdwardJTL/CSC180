def genAngle(n):
    if not isinstance(n, int):
        return False
    else:
        output = 360.0/n
        return output


def find(a,b):
    if (not isinstance(a, str) or (not isinstance(a, str))):
        return False
    else:
        if b in a:
            return 0
        else:
            return -1



print('%f' % (genAngle(8)))
print(find('xd heyasdfasdf xd','yas'))
