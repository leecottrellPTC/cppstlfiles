#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Country
{
private:
	string code;
	double latitude;
	double longitude;
	string name;
public:
#pragma region constructors

	Country() {
		code = "";
		latitude = 0;
		longitude = 0;
		name = "";
	}

	Country(string Code, double Lat, double Lon, string Name) {
		code = Code;
		latitude = Lat;
		longitude = Lon;
		name = Name;
	}
#pragma endregion

#pragma region setters and getters
	inline string getCode() {
		return code;
	}
	inline double getLatitude() {
		return latitude;
	}
	inline double getLongitude() {
		return longitude;
	}
	inline string getName() {
		return name;
	}

	inline void setCode(string Code) {
		code = Code;
	}
	inline void setLatitude(double Lat) {
		latitude = Lat;
	}
	inline void setLongitude(double Lon) {
		longitude = Lon;
	}
	inline void setName(string Name) {
		name = Name;
	}
#pragma endregion



#pragma region comparison operators
	
	friend bool operator >(Country& lhs, const Country& rhs) {
		return lhs.code > rhs.code;
	}
	friend bool operator<(Country& lhs, const Country& rhs) {
		return lhs.code < rhs.code;
	}
	friend bool operator>=(Country& lhs, const Country& rhs) {
		return lhs.code >= rhs.code;
	}
	friend bool operator<=(Country& lhs, const Country& rhs) {
		return lhs.code <= rhs.code;
	}

	friend bool operator !=(Country& lhs, Country& rhs) {
		return ((lhs.code != rhs.code) ||
			(lhs.latitude != rhs.latitude) ||
			(lhs.longitude != rhs.longitude) ||
			(lhs.name != rhs.name));
	}

	friend bool operator==(Country& lhs, const Country& rhs) {
		return ((lhs.code == rhs.code) &&
			(lhs.latitude == rhs.latitude) &&
			(lhs.longitude == rhs.longitude) &&
			(lhs.name == rhs.name));
	}

	

#pragma endregion

#pragma region io operators

		friend ostream& operator <<(ostream & out, const Country & item) {
			out << item.name << "(" << item.latitude << "," << item.longitude << ")";

			return out;
		}

		friend istream& operator >>(istream& in, Country& item) {
			in >> item.code;
			in >> item.latitude;
			in >> item.longitude;
			in.clear();
			in.ignore(100, '\n');

			getline(in, item.name);
			return in;
		}

#pragma endregion
};

