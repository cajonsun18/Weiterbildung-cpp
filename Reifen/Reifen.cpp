#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
	//setlocale(LC_ALL, "de_DE.utf8");

	double profil_neu = 0,
		profil_akt = 0,
		profil_sicher = 0,
		verschleiss = 0,
		verschleiss_km = 0,
		gef_km = 0,
		profil_rest = 0,
		rest_km = 0,
		rest_dauer = 0,
		jahr_km = 0;

	cout << "Profiltiefe neuer Reifen (in mm): ";
	cin >> profil_neu;
	cout << "Profiltiefe aktueller Reifen (in mm): ";
	cin >> profil_akt;
	cout << "Sicherheitsprofiltiefe (in mm): ";
	cin >> profil_sicher;
	cout << "Gefahrene Kilometer: ";
	cin >> gef_km;
	cout << "Jahreskilometerleistung: ";
	cin >> jahr_km;

	verschleiss = profil_neu - profil_akt;
	verschleiss_km = verschleiss/gef_km;
	profil_rest = profil_akt - profil_sicher;
	rest_km = profil_rest / verschleiss_km;
	rest_dauer = rest_km / jahr_km * 12;

	cout << setw(20) << "Verschleiss: " << setw(10) << verschleiss << " mm" << endl;
	cout << setw(20) << "Verschleiss pro km: " << setw(10) << verschleiss_km << " mm" << endl;
	cout << setw(20) << "Restprofiltiefe: " << setw(10) << profil_rest << " mm" << endl;
	cout << setw(20) << "Restkilometer: " << setw(10) << rest_km << " km" << endl;
	cout << setw(20) << "Restdauer: " << setw(10) << rest_dauer << " Monate" << endl;
}