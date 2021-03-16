def solution(x):
    str = ""
    for ch in x:
        num = ord(ch) - 97
        if num >= 0 and num <= 26:
            newch = chr(97 + (26 - (ord(ch)- 96)))
            str += newch
        else:
            str += ch
    return str

str = solution("_|`abcdefghijklmnopqrstuvwxyz{|")



print(str)
