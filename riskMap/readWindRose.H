Info << "Reading file constant/windRose.dat" << nl << endl;
string filename = "constant/windRose.dat";
ifstream file(filename);   
// Force file check
if (!file.is_open()) 
{
    cout << "Error opening file " << filename << endl;
    return 1;
}
while (file >> number) {
        windRoseData.push_back(number);
}  
// Close file
file.close();