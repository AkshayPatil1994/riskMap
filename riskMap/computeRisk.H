// Decide if the multiplication factor is unity or not
if(windRoseWeight.value() == 1)
{
    multiplicationFactor  = windRoseData[totalIterations];
}

volScalarField magU = mag(U);
// Sum the Uavg
Uavg = Uavg + multiplicationFactor*magU;
// Sum the kavg
kavg = kavg + multiplicationFactor*k;

// Loop over all the elements and check if the value is larger than given parameters
forAll(risk, cellID)
{
    if(magU[cellID]/Uinfty.value() > alpha.value())
    {
            risk[cellID] = 1.0;
    }
    if(k[cellID]/(Uinfty.value()*Uinfty.value()) < beta.value())
    {
        risk[cellID] = 0.0;
    }
}

// Compute the sum
P_risk = P_risk + risk;

// Write the risk field to file
risk.write();