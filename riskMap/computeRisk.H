volScalarField magU = mag(U);

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