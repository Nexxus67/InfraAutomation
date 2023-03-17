#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class VirtualMachine {
public:
    VirtualMachine(int id, string name, int cpu, int ram, int disk) :
        m_id(id), m_name(name), m_cpu(cpu), m_ram(ram), m_disk(disk) {}

    int getId() const { return m_id; }
    string getName() const { return m_name; }
    int getCpu() const { return m_cpu; }
    int getRam() const { return m_ram; }
    int getDisk() const { return m_disk; }

    void start() {
        cout << "Starting virtual machine " << m_name << endl;
        // Code to start the virtual machine...
    }

    void stop() {
        cout << "Stopping virtual machine " << m_name << endl;
        // Code to stop the virtual machine...
    }

private:
    int m_id;
    string m_name;
    int m_cpu;
    int m_ram;
    int m_disk;
};

class VirtualMachineManager {
public:
    void addVirtualMachine(VirtualMachine vm) {
        m_vms.push_back(vm);
    }

    void startAllVirtualMachines() {
        for (auto& vm : m_vms) {
            vm.start();
            // Wait for the virtual machine to start up...
            this_thread::sleep_for(chrono::seconds(30));
        }
    }

    void stopAllVirtualMachines() {
        for (auto& vm : m_vms) {
            vm.stop();
        }
    }

    void scaleUp(int cpu, int ram, int disk) {
        // Code to provision additional virtual machines...
        cout << "Provisioning additional virtual machines with " << cpu << " CPUs, " << ram << "GB RAM, and " << disk << "GB disk space..." << endl;
    }

    void scaleDown() {
        // Code to remove unneeded virtual machines...
        cout << "Removing unneeded virtual machines..." << endl;
    }

private:
    vector<VirtualMachine> m_vms;
};

int main() {
    VirtualMachineManager vmManager;

    // Add some virtual machines to the manager...
    vmManager.addVirtualMachine(VirtualMachine(1, "Web Server", 2, 8, 50));
    vmManager.addVirtualMachine(VirtualMachine(2, "Database Server", 4, 16, 100));

    // Start all virtual machines...
    vmManager.startAllVirtualMachines();

    // Wait for some time, then scale up the system...
    this_thread::sleep_for(chrono::minutes(30));
    vmManager.scaleUp(4, 32, 200);

    // Wait for some time, then stop all virtual machines...
    this_thread::sleep_for(chrono::minutes(60));
    vmManager.stopAllVirtualMachines();

    return 0;
}
