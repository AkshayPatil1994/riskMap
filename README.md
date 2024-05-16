# riskMap
This OpenFOAM utility computes a risk map using a non-dimensional velocity, alpha, and beta input parameters 


## How to compile?

- Copy the `riskMap` directory to `$HOME/OpenFOAM/<user>-<version>/applications/utilities/`. Replace <user> with your username and <version> with your version name.
- Compile the application by typing `wmake`

## How to use the utility

- Arrange the results of various wind directions .or. time results (either way its a risk over time/direction that is averaged) into different directories in serial `1`,`2`,`3`, so on ...
- Choose the right parameters in `flowProperties` and place this file in `constant`
- Make sure deltaT, startTime, endTime are set according to the way the results are arranged so each timestep is one snapshot
- Place the `windRose.dat` file in `constant` directory with the file contents such that the total number of snapshots are equal to the elements in the data file.
- Run `riskMap`

### This code was written listening to the wonderful album `Àmr` by Ihsahn
