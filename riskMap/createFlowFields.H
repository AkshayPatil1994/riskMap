Info<< "Reading the risk parameters defined in flowProperties" << endl;

volScalarField risk
(
    IOobject
    (
        "risk",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("risk", dimensionSet(0,0,0,0,0,0,0), 0.0)
);

volScalarField P_risk
(
    IOobject
    (
        "P_risk",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("P_risk", dimensionSet(0,0,0,0,0,0,0), 0.0)
);

volScalarField Uavg
(
    IOobject
    (
        "Uavg",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("Uavg", dimensionSet(0,1,-1,0,0,0,0), 0.0)
);

volScalarField kavg
(
    IOobject
    (
        "kavg",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("kavg", dimensionSet(0,2,-2,0,0,0,0), 0.0)
);

Info<< "Reading flowProperties\n" << endl;

IOdictionary flowProperties
(
    IOobject
    (
        "flowProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar Uinfty
(
      "Uinfty",
      dimensionSet(0, 0, 0, 0, 0, 0, 0),
      flowProperties
);

dimensionedScalar alpha
(
      "alpha",
      dimensionSet(0, 0, 0, 0, 0, 0, 0),
      flowProperties
);

dimensionedScalar beta
(
      "beta",
      dimensionSet(0, 0, 0, 0, 0, 0, 0),
      flowProperties
);

dimensionedScalar windRoseWeight
(
    "windRoseWeight",
    dimensionSet(0, 0, 0, 0, 0, 0, 0),
    flowProperties
);
