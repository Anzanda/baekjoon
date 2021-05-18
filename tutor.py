sample_list = ["goorm", "hello", "out of range error", "objective function", "open-source"]

def yoongu(n):
    return sample_list[n].count('o')

sample_list.sort(key= lambda el: el.count('o'))
print(sample_list)