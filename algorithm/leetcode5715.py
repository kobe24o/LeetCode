for n in range(2, 100, 2):
	print(n, end='\t')
	count = 1
	origin = [i for i in range(n)]
	arr = origin[::2]+origin[1::2]
	while origin != arr:
		arr = arr[::2]+arr[1::2]
		count += 1
	return count