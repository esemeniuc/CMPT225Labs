#!/usr/bin/env python
import subprocess
import sys,os

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)


passed = 0

n_tests = 3;


# Run a for loop of tests.
# Yes, we could ls to get a set of .in files
for i in range(1,n_tests+1):
    sys.stdout.write("Running test " + str(i) + "... ");
    rt = str(subprocess.call("./sum_array < " + str(i) + ".in > /dev/null",shell=True))
    # Compare rt to the ground truth.
    f = open (str(i) + ".er",'r')
    gt = f.read();

    if rt.strip() == gt.strip():
        passed += 1
        sys.stdout.write("passed\n");
    else:
        sys.stdout.write("failed\n");




sys.stdout.write("Passed " + str(passed) + " of " + str(n_tests) + " tests.\n");
