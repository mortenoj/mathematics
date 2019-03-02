import scipy as scpy;

turns = 3;

trans = scpy.matrix([
    [120/1296., 900/1296., 250/1296., 25/1296., 1/1296.],
    [       0.,  120/216.,   80/216.,  15/216.,  1/216.],
    [       0.,        0.,    25/36.,   10/36.,   1/36.],
    [       0.,        0.,        0.,     5/6.,    1/6.],
    [       0.,        0.,        0.,       0.,      1.],
]);

result = trans;

for i in range(1, turns):
    result = scpy.dot(result, trans);


print(result*100);
