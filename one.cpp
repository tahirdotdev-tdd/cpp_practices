#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Forward declarations
class Address;
class PhoneNumber;
class EmailAddress;
class Contact;
class ContactGroup;
class ContactList;
class SearchEngine;
class NameSearch;
class PhoneNumberSearch;
class UserInterface;

// --- Address Class ---
class Address
{
private:
    std::string street;
    std::string city;
    std::string stateProvince;
    std::string postalCode;

public:
    Address(const std::string &street = "", const std::string &city = "", const std::string &stateProvince = "", const std::string &postalCode = "")
        : street(street), city(city), stateProvince(stateProvince), postalCode(postalCode) {}

    void display() const
    {
        std::cout << "  Street: " << street << "\n";
        std::cout << "  City: " << city << "\n";
        std::cout << "  State/Province: " << stateProvince << "\n";
        std::cout << "  Postal Code: " << postalCode << "\n";
    }

    // Getters for potential use
    std::string getStreet() const { return street; }
    std::string getCity() const { return city; }
    std::string getStateProvince() const { return stateProvince; }
    std::string getPostalCode() const { return postalCode; }

    // Setters for potential use
    void setStreet(const std::string &street) { this->street = street; }
    void setCity(const std::string &city) { this->city = city; }
    void setStateProvince(const std::string &stateProvince) { this->stateProvince = stateProvince; }
    void setPostalCode(const std::string &postalCode) { this->postalCode = postalCode; }
};

// --- PhoneNumber Class ---
class PhoneNumber
{
private:
    std::string countryCode;
    std::string areaCode;
    std::string number;

public:
    PhoneNumber(const std::string &countryCode = "", const std::string &areaCode = "", const std::string &number = "")
        : countryCode(countryCode), areaCode(areaCode), number(number) {}

    void display() const
    {
        std::cout << "  Phone: +" << countryCode << " (" << areaCode << ") " << number << "\n";
    }

    // Getters for potential use
    std::string getCountryCode() const { return countryCode; }
    std::string getAreaCode() const { return areaCode; }
    std::string getNumber() const { return number; }

    // Setters for potential use
    void setCountryCode(const std::string &countryCode) { this->countryCode = countryCode; }
    void setAreaCode(const std::string &areaCode) { this->areaCode = areaCode; }
    void setNumber(const std::string &number) { this->number = number; }
};

// --- EmailAddress Class ---
class EmailAddress
{
private:
    std::string email;

public:
    EmailAddress(const std::string &email = "") : email(email) {}

    void display() const
    {
        std::cout << "  Email: " << email << "\n";
    }

    // Getter for potential use
    std::string getEmail() const { return email; }

    // Setter for potential use
    void setEmail(const std::string &email) { this->email = email; }
};

// --- Contact Class ---
class Contact
{
private:
    std::string name;
    PhoneNumber phoneNumber;
    EmailAddress emailAddress;
    Address address;

public:
    Contact(const std::string &name, const PhoneNumber &phoneNumber, const EmailAddress &emailAddress, const Address &address)
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress), address(address) {}

    void display() const
    {
        std::cout << "Name: " << name << "\n";
        phoneNumber.display();
        emailAddress.display();
        address.display();
        std::cout << "--------------------\n";
    }

    std::string getName() const { return name; }
    const PhoneNumber &getPhoneNumber() const { return phoneNumber; }
    const EmailAddress &getEmailAddress() const { return emailAddress; }
    const Address &getAddress() const { return address; }

    // Setters for potential use
    void setName(const std::string &name) { this->name = name; }
    void setPhoneNumber(const PhoneNumber &phoneNumber) { this->phoneNumber = phoneNumber; }
    void setEmailAddress(const EmailAddress &emailAddress) { this->emailAddress = emailAddress; }
    void setAddress(const Address &address) { this->address = address; }
};

// --- ContactGroup Class ---
class ContactGroup
{
private:
    std::string name;
    std::vector<Contact *> contacts;

public:
    ContactGroup(const std::string &name) : name(name) {}

    void addContact(Contact *contact)
    {
        contacts.push_back(contact);
    }

    void display() const
    {
        std::cout << "Group: " << name << "\n";
        for (const auto &contact : contacts)
        {
            contact->display();
        }
        std::cout << "====================\n";
    }

    std::string getName() const { return name; }
    const std::vector<Contact *> &getContacts() const { return contacts; }
};

// --- ContactList Class ---
class ContactList
{
private:
    std::vector<Contact *> contacts;

public:
    void addContact(Contact *contact)
    {
        contacts.push_back(contact);
    }

    void removeContact(const std::string &name)
    {
        contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                                      [&](Contact *c)
                                      { return c->getName() == name; }),
                       contacts.end());
    }

    void displayAllContacts() const
    {
        if (contacts.empty())
        {
            std::cout << "Contact list is empty.\n";
            return;
        }
        std::cout << "----- All Contacts -----\n";
        for (const auto &contact : contacts)
        {
            contact->display();
        }
    }

    std::vector<Contact *> searchContactByName(const std::string &name) const
    {
        std::vector<Contact *> results;
        for (const auto &contact : contacts)
        {
            if (contact->getName().find(name) != std::string::npos)
            {
                results.push_back(contact);
            }
        }
        return results;
    }

    std::vector<Contact *> searchContactByPhoneNumber(const std::string &number) const
    {
        std::vector<Contact *> results;
        for (const auto &contact : contacts)
        {
            if (contact->getPhoneNumber().getNumber().find(number) != std::string::npos)
            {
                results.push_back(contact);
            }
        }
        return results;
    }

    // Method to get a contact by name for group operations
    Contact *getContactByName(const std::string &name) const
    {
        for (const auto &contact : contacts)
        {
            if (contact->getName() == name)
            {
                return contact;
            }
        }
        return nullptr;
    }
};

// --- SearchEngine (Abstract Base Class) ---
class SearchEngine
{
public:
    virtual std::vector<Contact *> search(const ContactList &contactList, const std::string &query) const = 0;
    virtual ~SearchEngine() {}
};

// --- NameSearch (Derived from SearchEngine) ---
class NameSearch : public SearchEngine
{
public:
    std::vector<Contact *> search(const ContactList &contactList, const std::string &query) const override
    {
        return contactList.searchContactByName(query);
    }
};

// --- PhoneNumberSearch (Derived from SearchEngine) ---
class PhoneNumberSearch : public SearchEngine
{
public:
    std::vector<Contact *> search(const ContactList &contactList, const std::string &query) const override
    {
        return contactList.searchContactByPhoneNumber(query);
    }
};

// --- UserInterface Class ---
class UserInterface
{
private:
    ContactList contactList;
    std::vector<ContactGroup> contactGroups;

public:
    void run()
    {
        int choice;
        do
        {
            displayMenu();
            std::cin >> choice;
            std::cin.ignore(); // Consume the newline character

            switch (choice)
            {
            case 1:
                addContact();
                break;
            case 2:
                removeContact();
                break;
            case 3:
                displayAllContacts();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                createGroup();
                break;
            case 6:
                addContactToGroup();
                break;
            case 7:
                displayAllGroups();
                break;
            case 0:
                std::cout << "Exiting Contact Book.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\n";
        } while (choice != 0);
    }

private:
    void displayMenu() const
    {
        std::cout << "----- Contact Book Menu -----\n";
        std::cout << "1. Add New Contact\n";
        std::cout << "2. Remove Contact\n";
        std::cout << "3. Display All Contacts\n";
        std::cout << "4. Search Contact\n";
        std::cout << "5. Create New Group\n";
        std::cout << "6. Add Contact to Group\n";
        std::cout << "7. Display All Groups\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void addContact()
    {
        std::cout << "----- Add New Contact -----\n";
        std::string name, countryCode, areaCode, number, email, street, city, stateProvince, postalCode;

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Phone Country Code: ";
        std::getline(std::cin, countryCode);
        std::cout << "Phone Area Code: ";
        std::getline(std::cin, areaCode);
        std::cout << "Phone Number: ";
        std::getline(std::cin, number);
        PhoneNumber phone(countryCode, areaCode, number);

        std::cout << "Email: ";
        std::getline(std::cin, email);
        EmailAddress emailAddr(email);

        std::cout << "Street: ";
        std::getline(std::cin, street);
        std::cout << "City: ";
        std::getline(std::cin, city);
        std::cout << "State/Province: ";
        std::getline(std::cin, stateProvince);
        std::cout << "Postal Code: ";
        std::getline(std::cin, postalCode);
        Address addr(street, city, stateProvince, postalCode);

        Contact *newContact = new Contact(name, phone, emailAddr, addr);
        contactList.addContact(newContact);
        std::cout << "Contact added successfully.\n";
    }

    void removeContact()
    {
        std::cout << "----- Remove Contact -----\n";
        std::string name;
        std::cout << "Enter the name of the contact to remove: ";
        std::getline(std::cin, name);
        contactList.removeContact(name);
        std::cout << "Contact removed (if found).\n";
    }

    void displayAllContacts() const
    {
        contactList.displayAllContacts();
    }

    void searchContact() const
    {
        std::cout << "----- Search Contact -----\n";
        std::cout << "Search by (1) Name or (2) Phone Number? ";
        int searchChoice;
        std::cin >> searchChoice;
        std::cin.ignore();

        std::string query;
        std::cout << "Enter your search query: ";
        std::getline(std::cin, query);

        std::vector<Contact *> results;
        if (searchChoice == 1)
        {
            NameSearch nameSearch;
            results = nameSearch.search(contactList, query);
        }
        else if (searchChoice == 2)
        {
            PhoneNumberSearch phoneSearch;
            results = phoneSearch.search(contactList, query);
        }
        else
        {
            std::cout << "Invalid search choice.\n";
            return;
        }

        if (results.empty())
        {
            std::cout << "No contacts found matching your query.\n";
        }
        else
        {
            std::cout << "----- Search Results -----\n";
            for (const auto &contact : results)
            {
                contact->display();
            }
        }
    }

    void createGroup()
    {
        std::cout << "----- Create New Group -----\n";
        std::string groupName;
        std::cout << "Enter the name for the new group: ";
        std::getline(std::cin, groupName);
        contactGroups.emplace_back(groupName);
        std::cout << "Group '" << groupName << "' created successfully.\n";
    }

    void addContactToGroup()
    {
        std::cout << "----- Add Contact to Group -----\n";
        std::string groupName, contactName;

        std::cout << "Enter the name of the group: ";
        std::getline(std::cin, groupName);

        auto groupIt = std::find_if(contactGroups.begin(), contactGroups.end(),
                                    [&](const ContactGroup &group)
                                    { return group.getName() == groupName; });

        if (groupIt == contactGroups.end())
        {
            std::cout << "Group '" << groupName << "' not found.\n";
            return;
        }

        std::cout << "Enter the name of the contact to add to '" << groupName << "': ";
        std::getline(std::cin, contactName);

        Contact *contactToAdd = contactList.getContactByName(contactName);
        if (contactToAdd)
        {
            groupIt->addContact(contactToAdd);
            std::cout << "Contact '" << contactName << "' added to group '" << groupName << "'.\n";
        }
        else
        {
            std::cout << "Contact '" << contactName << "' not found in the contact list.\n";
        }
    }

    void displayAllGroups() const
    {
        if (contactGroups.empty())
        {
            std::cout << "No groups created yet.\n";
            return;
        }
        std::cout << "----- All Groups -----\n";
        for (const auto &group : contactGroups)
        {
            group.display();
        }
    }
};

int main()
{
    UserInterface ui;
    ui.run();
    return 0;
}