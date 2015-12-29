I can never remember how to convert the bits, so here are two bash scripts to symlink to ~/bin in case you need to convert between asdot and asplain.

In `bash`.
```
% dot2plain 65044:21
4262723605
% plain2dot 4262723605
65044:21
```

or

This is a more complete C version, probably just as broken.
```
% make asnconv
% ./asnconv 4262723631
% ./asnconv 65036.12
% ./asnconv 65412
```

asdot notation is deprecated, btw :)
