//
//  newDevice.h
//  slutProjekt
//
//  Created by Stran Rasoul on 2024-03-28.
//

#ifndef newDevice_h
#define newDevice_h

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Device{
private:
    string name;
    vector<string>connectedDevices;
public:
    Device(const string& name) : name(name) {}
    
    void addConnectedDevices(string deviceName){
        connectedDevices.push_back(deviceName);
    }
    
    vector<string> getConnectedDevices() const{
        return connectedDevices;
    }
    ////////////////////////////////////////
    //ÄNDRAD
    ///////////////////////////////////////
    void sideEffect() const{
        stringstream message;
        message << "say Hello from" << name;
#ifdef _WIN32
        // Windows-specific "side effect" (beep)
        Beep(750, 300);  // Frequency: 750 Hz, Duration: 300 ms
        
#elif __APPLE__
        // macOS-specific "side effect" (say hello)
        system(message.str().c_str());
#else
        // Default "side effect" ifall programmet ej körs på Windows/Mac
        cout << "Performing default action on device: " << name << endl;
#endif
    }

    const string& getName() const {return name;}
};

class DeviceOptions {
private:
    vector<Device> devices;
    
public:
    
    bool deviceExists(const string&name) const{
        return find_if(devices.begin(), devices.end(), [&](const Device&d){
            return d.getName() == name;
        }) != devices.end();
    }
    
    void createDevice(const string& name) {
        if(deviceExists(name)){
            cout << name << " already exists!" << endl;
        }
        else{
            devices.push_back(Device(name));
            cout << name << " created!" << endl;
        }
        
    }
    
    void deleteDevice(const std::string& name) {
        auto it = find_if(devices.begin(), devices.end(),[&](const Device& d){
            return d.getName() == name;
        });
        
        if (it != devices.end()) {
            devices.erase(it);
            cout << name << " Deleted." << endl;
        } else {
            cout << "Device not found." << endl;
        }
    }
    
    void connectDevices(const string& device1, const string& device2) {
        
        auto it1 = find_if(devices.begin(), devices.end(), [&](const Device& d){
            return d.getName() == device1; });
        
        auto it2 = find_if(devices.begin(), devices.end(), [&](const Device& d){
            return d.getName() == device2; });
        
        if (it1 != devices.end() && it2 != devices.end()) {
            it1->addConnectedDevices(device2);
            it2->addConnectedDevices(device1);
            cout<<"Connected " << device1 << " to " << device2 << endl;
            //////////////////////
            ///ÄNDRAD
            it1->sideEffect();
            it2->sideEffect();
            /////////////////////
        } else
            cout<<"Can not connect. One or both devices are missing."<<endl;
    }
    
    void pingDevice(const string& name) {
        auto it = find_if(devices.begin(), devices.end(), [&](const Device& d) {
            return d.getName() == name;
        });
        
        if (it != devices.end()) {
            cout << it->getName() << " got pinged!" << endl;
            it->sideEffect();
            
            // Ping connected devices if any
            const vector<string>& connectedDevices = it->getConnectedDevices();
            //if (!connectedDevices.empty()) {
                for (const string& connectedDevice : connectedDevices) {
                    // Retrieve the connected device and ping it
                    auto connectedIt = find_if(devices.begin(), devices.end(), [&](const Device& d) {
                        return d.getName() == connectedDevice;
                    });
                    
                    if (connectedIt != devices.end()) {
                        cout << connectedDevice << " (connected to " << it->getName() << ") got pinged!" << endl;
                    }
                }
            //}
        } else {
            cout << "Device not found!" << endl;
        }
    }
    
   
    void printDevices() const {
        for (const Device& device : devices) {
            cout << device.getName() << endl;
            
            const vector<string>& connectedDevices = device.getConnectedDevices();
            
            ///////////////////////
            ///ÄNDRAD
            ///////////////////////
            
            if (!connectedDevices.empty()) {
                cout << "(connected to: ";
                for (size_t i = 0; i < connectedDevices.size(); ++i) {
                    cout << connectedDevices[i] << ")"<< endl;
                    if (i < connectedDevices.size() - 1) {
                        cout << ", ";
                    }
                }
            }
            cout << "" <<endl;
        }
    }
};

#endif /* newDevice_h */
