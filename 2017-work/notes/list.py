#LISTS

l = [[1,2],[3,4]];

s = l;
s.append([5,6]); # l = [[1,2],[3,4],[5,6]]; not copied but referance

s = copy(l); # copy
s.append([7,8]); # l = [[1,2],[3,4],[5,6]]; copied not referanced
s[0].append(3); # would not work

s = copy.deepcopy(l); # a real copy of whole of l
s[0].append(3); # would work
