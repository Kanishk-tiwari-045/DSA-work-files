class Flight {
    constructor(airline, capacity) {
      this.airline = airline;
      this.capacity = capacity;
      this.bookedSeats = 0;
    }
  
    isAvailable() {
      return this.capacity > this.bookedSeats;
    }
  
    bookSeat() {
      if (this.isAvailable()) {
        this.bookedSeats++;
        return this.bookedSeats;
      } else {
        return null;
      }
    }
  }
  
  class Ticket {
    constructor(passengerName, age, origin, destination, flight) {
      this.ticketId = null;
      this.passenger = {
        name: passengerName,
        age: age,
        seatNumber: null,
      };
      this.origin = origin;
      this.destination = destination;
      this.departureDate = new Date().toLocaleDateString("en-US");
      this.departureTime = new Date().toLocaleTimeString("en-US");
      this.flight = flight;
    }
  
    bookTicket() {
      let seatNumber = this.flight.bookSeat();
      if (seatNumber) {
        this.passenger.seatNumber = seatNumber;
        this.ticketId = seatNumber + this.flight.airline;
        console.log(
          "Ticket booked successfully! Seat number: " + seatNumber + "\n"
        );
        console.log(this); // This will log the ticket details
      } else {
        console.log("Sorry, seats are not available");
      }
    }
  }
  let ticketsArray = [];
  
  // Example usage:
  let deltaFlight = new Flight("vistara", 100);
  let ticket = new Ticket("John Doe", 30, "London", "New York", deltaFlight);
  ticket.bookTicket();
  
  ticketsArray.push(ticket);