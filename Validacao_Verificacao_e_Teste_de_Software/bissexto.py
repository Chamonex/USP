
def e_bissexto(a):
    if a <= 0 or a > 9999:
        return False
    if a <= 1752:
        if a % 4 == 0:
            return True
        else:
            return False
    else:
        if a % 400 == 0:
            return True
        if a % 100 == 0:
            return False
        if a % 4 == 0:
            return True
