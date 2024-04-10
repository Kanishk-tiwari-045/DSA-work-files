// #include <iostream>
// #include <vector>
// #include <string>

// int main() {
//     // List of major festive holidays
//     std::vector<std::string> festive_dates = {
//         "January 1", "January 26", "January 15",
//         "February (Basant Panchami)",
//         "March (Holi)",
//         "April 13 or 14 (Baisakhi)", "Ram Navami",
//         "May (Eid-ul-Fitr)", "Buddha Purnima",
//         "June (Rath Yatra)",
//         "July (Guru Purnima)",
//         "August (Raksha Bandhan, Krishna Janmashtami)",
//         "September (Ganesh Chaturthi, Onam)",
//         "October (Durga Puja, Diwali)",
//         "November (Guru Nanak Jayanti, Chhath Puja)",
//         "December 25 (Christmas), December 31 (New Year's Eve)"
//     };

//     // Print the festive dates
//     for (const auto& date : festive_dates) {
//         std::cout << date << std::endl;
//     }

//     return 0;
//     }






// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// // Define a structure for refund details
// struct RefundDetails {
//     int refundApprovedWithin7Days;
//     int refundApprovedAfter7Days;
// };

// // Define a structure for damage charges
// struct DamageCharges {
//     int minorDamage;
//     int majorDamage;
// };

// // Define a structure for luggage loss details
// struct LuggageLossDetails {
//     int reimbursementAmount;
//     int goodwillVoucher;
// };

// // Define a structure for airline information including refund, damage, and luggage loss details
// struct Airline {
//     string airlineName;
//     double cancellationCharges;
//     RefundDetails refundDetails;
//     DamageCharges damageCharges;
//     LuggageLossDetails luggageLossDetails;
// };

// // Function to calculate refund charges
// int calculateRefundCharges(bool refundApprovedWithin7Days) {
//     return refundApprovedWithin7Days ? 0 : 1000;
// }

// // Function to calculate damage charges
// int calculateDamageCharges(bool majorDamage) {
//     return majorDamage ? 3500 : 0;
// }

// // Function to process luggage loss
// pair<int, int> processLuggageLoss(int lossAmount) {
//     const int maxReimbursement = 35000;
//     const int goodwillVoucher = 1800;
//     int reimbursementAmount = min(lossAmount, maxReimbursement);
//     return {reimbursementAmount, goodwillVoucher};
// }

// int main() {
//     // Sample data for airlines
//     Airline airlines[] = {
//         {"Air India", 1800, {0, 1000}, {0, 3500}, {35000, 1800}},
//         {"Air Asia", 1800, {0, 1000}, {0, 3500}, {35000, 1800}},
//         {"IndiGo", 1800, {0, 1000}, {0, 3500}, {35000, 1800}}
//     };

//     // Display results
//     for (const auto& airline : airlines) {
//         cout << "-----------------------------------------------------------------------" << endl;
//         cout << "Airline: " << airline.airlineName << endl;
//         cout << "Cancellation Charges: " << airline.cancellationCharges << " INR" << endl;
//         cout << "Refund Charges (within 7 days): " << calculateRefundCharges(airline.refundDetails.refundApprovedWithin7Days) << " INR" << endl;
//         cout << "Refund Charges (after 7 days): " << calculateRefundCharges(airline.refundDetails.refundApprovedAfter7Days) << " INR" << endl;
//         cout << "Minor Damage Charges: " << airline.damageCharges.minorDamage << " INR" << endl;
//         cout << "Major Damage Charges: " << airline.damageCharges.majorDamage << " INR" << endl;
//         auto luggageLoss = processLuggageLoss(airline.luggageLossDetails.reimbursementAmount);
//         cout << "Luggage Reimbursement: " << luggageLoss.first << " INR" << endl;
//         cout << "Goodwill Voucher: " << luggageLoss.second << " INR" << endl;
//         cout << "-----------------------------------------------------------------------" << endl;
//         cout << endl;
//      }

//     return 0;
// }