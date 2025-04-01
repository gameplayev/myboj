import sys
input = sys.stdin.readline
n = int(input())
lis = list(map(int , input().rstrip().split()))
arr = sorted(set(lis))
dic = {}
seq = 0
for i in arr:
    dic[i] = seq
    seq += 1

for i in lis:
    print(dic[i] , end = " ")