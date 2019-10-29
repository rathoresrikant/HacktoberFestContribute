def compress(nstring):
	string=str(nstring)
	dictionary = {chr(i):i for i in range(65,123)}
     
	last = 256
	p = ""
	result = []
     
	for c in string:
		pc = p+c
    		if pc in dictionary:
    			p = pc
    		else:
    			result.append(dictionary[p])
    			dictionary[pc] = last
    			last += 1
    			p = c
     
	if p != '':
		result.append(dictionary[p])
     
	return result

def de_compress(arr):
	dictionary = {i:chr(i) for i in range(65,123)}
	last = 256
	     
	result = []
	p = arr.pop(0)
	result.append(dictionary[p])
     
	for c in arr:
		if c in dictionary:
    			entry = dictionary[c]
    			result.append(entry)
    			dictionary[last] = dictionary[p] + entry[0]
    			last += 1
    			p = c
		
    	return(''.join(result))
	

def main():
	n=raw_input("Enter Message to be compressed:")
	
	m= compress(str(n)) 
	print("Compressed code :")
	print(m)

	print ("Decompressed message:")
	k=str( de_compress(m))
	print(k)

main()
