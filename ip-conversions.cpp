#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char opt = ' ';
	while(opt != '0')
	{
		cout << endl;
		cout << "1 - Create IP Address from Network Decimal" << endl;
		cout << "2 - Create IP Address from Host Decimal" << endl;
		cout << "3 - Create Network Decimal from IP Address" << endl;
		cout << "4 - Create a Host Decimal from IP Address" << endl;
		cout << "5 - Convert Host Decimal to Network Decimal" << endl;
		cout << "6 - Convert Network Decimal to Host Decimal" << endl;
		cout << "0 - Quit" << endl;
		cout << "Option: ";
		cin >> opt;

		switch(opt)
		{
			case '0':					//Do Nothing, quit...
			{
				break;
			}
			case '1':					//IP Address to network decimal
			{
				uint32_t val = 0;
				printf("Please enter a network decimal to convert to an IP Address: ");
				fflush(stdout);
				cin >> val;

				struct in_addr addr = {val};
				printf("%u converted to an IP Address is: %s\n", val, inet_ntoa(addr));

				break;
			}
			case '2':					//Host Decimal to network decimal to ASCII IP Address
			{
				uint32_t val = 0;
				printf("Please enter a host decimal to convert to an IP Address: ");
				fflush(stdout);
				cin >> val;
				cout << endl;

				uint32_t networkVal = htonl(val);
				struct in_addr addr = {networkVal};

				// cout << "Aquired host decimal: " << val << endl;
				// cout << "Network tranlsation:  " << networkVal << endl;

				printf("%u converted to IP Address is: %s\n", val, inet_ntoa(addr));
				break;
			}
			case '3':					//Network decimal to ASCII IP Address
			{
				string val = "";
				printf("Please enter an IP Address to convert to a network decimal: ");
				fflush(stdout);
				cin >> val;

				struct sockaddr_in addr;
				inet_pton(AF_INET, val.c_str(), &(addr.sin_addr));

				// Change it back
				// char str[INET_ADDRSTRLEN];
				// inet_ntop(AF_INET, &(addr.sin_addr), str, INET_ADDRSTRLEN);

				printf("%s convert to decimal is: %d\n", val.c_str(), addr.sin_addr.s_addr);
				break;
			}
			case '4':					//ASCII IP Address to host decimal
			{
				string val = "";
				printf("Please enter an IP Address to convert to a host decimal: ");
				fflush(stdout);
				cin >> val;

				struct sockaddr_in addr;
				inet_pton(AF_INET, val.c_str(), &(addr.sin_addr));

				printf("%s convert to host decimal is: %u\n", val.c_str(), ntohl(addr.sin_addr.s_addr));
				break;
			}
			case '5':					//Host Decimal to Network Decimal
			{
				uint32_t hostDecimal = 0;
				printf("Please enter a host decimal to convert to network decimal: ");
				fflush(stdout);
				cin >> hostDecimal;

				uint32_t networkVal = htonl(hostDecimal);

				printf("%u converted to network decimal is: %u", hostDecimal, networkVal);
				break;
			}
			case '6':					//Network Decimal to Host Decimal
			{
				uint32_t networkDecimal = 0;
				printf("Please enter a network decimal to convert to host decimal: ");
				fflush(stdout);
				cin >> networkDecimal;

				uint32_t hostDecimal = ntohl(networkDecimal);

				printf("%u converted to host decimal is: %u", networkDecimal, hostDecimal);
				break;
			}
			default:
			{
				printf("Unknown option value %c\n", opt);
				break;
			}
		}
	}
}