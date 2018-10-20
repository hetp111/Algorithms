#https://www.hackerrank.com/challenges/python-string-formatting/problem

u = int(input())
pad = len(str(bin(u)))-2
for i in range(1, u+1):
    x = (str(i), str(oct(i)[2:]), hex(i)[2:].upper(), str(bin(i)[2:]))
    print(x[0].rjust(pad), x[1].rjust(pad), x[2].rjust(pad), x[3].rjust(pad))
    
    
