r = int(input()) # first starting range
l = int(input()) # second starting range
proper_factors = []
perfect_number = []
if r > l: # so that it won't create problem if user enter bigger number first
    r, l = l, r
while r <= l:
    index = 1
    while index < r:
        if r % index == 0:
            proper_factors.append(index)
        index += 1
    if sum(proper_factors) == r:
        perfect_number.append(r)
    r += 1
    proper_factors = []
if len(perfect_number) == 0:
    print('No perfect Number In Given Range')
else:
    for i in perfect_number:
        print(i)

