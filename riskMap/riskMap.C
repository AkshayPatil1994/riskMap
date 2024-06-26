/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    riskMap

Description

\*---------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFlowFields.H"
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    float multiplicationFactor = 1.0;

    Info << nl << "Risk values used are alpha: " << alpha.value() << " beta: " << beta.value() << nl << endl;
    
    // Declare windRoseData to be accessible everywhere
    std::vector<float> windRoseData;
    float number;
    // Read wind rose data file if user requests
    if(windRoseWeight.value() == 1)
    {
        #include "readWindRose.H"
        Info << "Size of the windrose.dat: " << windRoseData.size() << " items"<< nl << endl;
    }
    int totalIterations = 0;
    for (runTime; !runTime.end(); runTime++)
    {
        // Dump time information to screen
        Info << "Time: " << runTime.value() << "s" << nl << endl;
        // Read the U and TKE at the current time
        #include "updateUTKE.H"
        // Compute the risk metric
        #include "computeRisk.H"  
        // Increment the total number of iterations
        totalIterations = totalIterations + 1;       
    }
    // Now compute the average and divide it by the total number of samples
    Info << "Writing P_risk to file" << nl << endl;
    P_risk = P_risk/totalIterations;
    P_risk.write();
    Info << "Writing Uavg to file" << nl << endl;
    if(windRoseWeight.value() != 1)
    {
        Uavg = Uavg/totalIterations;
        kavg = kavg/totalIterations;
    }
    Uavg.write();
    Info << "Writing kavg to file" << nl << endl;
    kavg.write();
    // Output Time information to screen
    Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
        << nl << endl;

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
