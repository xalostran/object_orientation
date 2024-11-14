//
//  main.cpp
//  slutProjekt
//
//  Created by Stran Rasoul on 2024-03-24.
//

//
//  main.cpp
//  slutProjekt
//
//  Created by Stran Rasoul on 2023-12-13.
//

#include <iostream>
#include <limits>
#include "device.hpp"

using namespace std;

int main() {
    DeviceOptions deviceOpt;
    
    int choices = 0;
    string deviceName;
    do {
        cout<<"Make your choice: "<<endl;
        cout<<"1. Create device"<<endl;
        cout<<"2. Delete device"<<endl;
        cout<<"3. Connect devices"<<endl;
        cout<<"4. Ping device"<<endl;
        cout<<"5. Print devices"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<"> ";
        
        while (!(cin >> choices)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input. Please enter a number."<<endl;
            cout<<"> ";
        }
        
        switch (choices) {
            case 1:
                cout<<"Device name: ";
                cin>>deviceName;
                deviceOpt.createDevice(deviceName);
                break;
            case 2:
                cout<<"Enter device name to delete: ";
                cin>>deviceName;
                deviceOpt.deleteDevice(deviceName);
                break;
            case 3: {
                string device1, device2;
                cout<<"Name of first device: ";
                cin>>device1;
                cout<<"Name of second device: ";
                cin>>device2;
                deviceOpt.connectDevices(device1, device2);
                break;
            }
            case 4:
                cout<<"Enter device name to ping: ";
                cin>>deviceName;
                deviceOpt.pingDevice(deviceName);
                break;
            case 5:
                cout << "\nDevices:" << endl;
                deviceOpt.printDevices();
                break;
            case 6:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Try again."<<endl;
        }
        
    }while(choices!=6);
    
}


