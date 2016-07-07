#!/usr/bin/env python
import subprocess
import sys,os

passed = 0

n_tests = 6;

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)

# Run a for loop of tests.
sys.stdout.write("Running merge_sort on battery of " + str(n_tests) + " tests.\n");
for i in range(1,n_tests+1):
    sys.stdout.write("  Running test " + str(i) + "...");
    # Run the merge_sort with this test input, redirect output to i.out.
    subprocess.call("./merge_sort" + " < " + str(i) + ".in" + " > " + str(i) + ".out",shell=True);
    # Compare output to the ground truth.
    rt = subprocess.call("diff -b " + str(i) + ".out " + str(i) + ".er > /dev/null",shell=True);


    
    subprocess.call("rm " + str(i) + ".out",shell=True)
    if rt == 0:
        passed += 1
        sys.stdout.write( "passed\n");
    else:
        sys.stdout.write( "failed\n");




sys.stdout.write("Passed " + str(passed) + " of " + str(n_tests) + " tests.\n")
