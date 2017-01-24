def subset(a):
	length=len(a)
	# total number of set
	tot=2**length
	print("[")
	for i in range(tot):
		print("    [",end='')
		# now is for determine which bit to print
		now=0
		ifeverprint=0
		while(i):
			if(i-((i>>1)<<1)):
				if(now>0 and ifeverprint>0):
					print(',',end='')
				# always get the least bit
				print(a[now],end='')
				ifeverprint+=1
			i=i>>1
			now+=1
		print("],")	
	print("]")	


a=[1,2,3,11]	
subset(a)


