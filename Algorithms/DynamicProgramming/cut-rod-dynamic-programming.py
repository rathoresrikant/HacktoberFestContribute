def cut_rod(p,n):
	if n == 0:
		return 0
	q = 0
	for i in range(n):
		q = max(q,p[i] + cut_rod(p,n-i))
	return q

profits = [1,5,8,9,10,17,17,20,24,30]
n = 2
max_profit = cut_rod(profits,n)
print(max_profit)