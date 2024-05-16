# riskMap
This OpenFOAM utility computes a risk map using a non-dimensional velocity, alpha, and beta input parameters 


## How to compile?

- Copy the `riskMap` directory to `$HOME/OpenFOAM/<user>-<version>/applications/utilities/`. Replace <user> with your username and <version> with your version name.
- Compile the application by typing `wmake`

## How to use the utility

- Arrange the results of various wind directions .or. time results (either way its a risk over time/direction that is averaged) into different directories in serial `1`,`2`,`3`, so on ...
- Run `riskMap`

### This code was written listening to the wonderful album `Àmr` by Ihsahn
