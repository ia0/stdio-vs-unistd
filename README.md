File operations: stdio vs. unistd
=================================

It looks like stdio is five times slower than unistd:

    % ./test.sh 4K 16M 64M 256M
    Size 4K:
    stdio:   0.00  456
    unistd:  0.00  424
    Size 16M:
    stdio:   0.44  456
    unistd:  0.08  428
    Size 64M:
    stdio:   1.75  456
    unistd:  0.32  428
    Size 256M:
    stdio:   7.40  456
    unistd:  1.32  428

Why?
