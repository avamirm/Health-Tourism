CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/Handler.o: src/Handler.cpp include/Handler.hpp include/User.hpp include/HealthTourism.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp include/exceptions.hpp
	$(CC) $(CF) -c src/Handler.cpp -o $(BUILD_DIR)/Handler.o

$(BUILD_DIR)/HealthTourism.o: src/HealthTourism.cpp include/HealthTourism.hpp include/Handler.hpp include/Supporter.hpp include/Patient.hpp include/User.hpp include/exceptions.hpp server/server.hpp
	$(CC) $(CF) -c src/HealthTourism.cpp -o $(BUILD_DIR)/HealthTourism.o

$(BUILD_DIR)/CreditCard.o: src/CreditCard.cpp include/CreditCard.hpp include/date.hpp
	$(CC) $(CF) -c src/CreditCard.cpp -o $(BUILD_DIR)/CreditCard.o

$(BUILD_DIR)/exceptions.o: src/exceptions.cpp include/exceptions.hpp
	$(CC) $(CF) -c src/exceptions.cpp -o $(BUILD_DIR)/exceptions.o

$(BUILD_DIR)/FinalBill.o: src/FinalBill.cpp include/FinalBill.hpp
	$(CC) $(CF) -c src/FinalBill.cpp -o $(BUILD_DIR)/FinalBill.o

$(BUILD_DIR)/MedicalDocument.o: src/MedicalDocument.cpp include/MedicalDocument.hpp
	$(CC) $(CF) -c src/MedicalDocument.cpp -o $(BUILD_DIR)/MedicalDocument.o

$(BUILD_DIR)/Patient.o: src/Patient.cpp include/Patient.hpp include/User.hpp  include/CreditCard.hpp include/exceptions.hpp
	$(CC) $(CF) -c src/Patient.cpp -o $(BUILD_DIR)/Patient.o

$(BUILD_DIR)/Payment.o: src/Payment.cpp include/Payment.hpp include/date.hpp
	$(CC) $(CF) -c src/Payment.cpp -o $(BUILD_DIR)/Payment.o

$(BUILD_DIR)/RecordesOfServices.o: src/RecordesOfServices.cpp include/RecordesOfServices.hpp include/date.hpp
	$(CC) $(CF) -c src/RecordesOfServices.cpp -o $(BUILD_DIR)/RecordesOfServices.o

$(BUILD_DIR)/Requests.o: src/Requests.cpp include/Requests.hpp include/date.hpp include/Supporter.hpp
	$(CC) $(CF) -c src/Requests.cpp -o $(BUILD_DIR)/Requests.o

$(BUILD_DIR)/Supporter.o: src/Supporter.cpp include/Supporter.hpp include/User.hpp
	$(CC) $(CF) -c src/Supporter.cpp -o $(BUILD_DIR)/Supporter.o

$(BUILD_DIR)/User.o: src/User.cpp include/User.hpp include/Requests.hpp
	$(CC) $(CF) -c src/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/main.o: src/main.cpp include/HealthTourism.hpp include/Handler.hpp include/Supporter.hpp include/Patient.hpp include/User.hpp include/exceptions.hpp server/server.hpp
	$(CC) $(CF) -c src/main.cpp -o $(BUILD_DIR)/main.o

myserver.out: $(BUILD_DIR)/main.o $(BUILD_DIR)/Handler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/HealthTourism.o $(BUILD_DIR)/CreditCard.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/FinalBill.o $(BUILD_DIR)/MedicalDocument.o $(BUILD_DIR)/Patient.o $(BUILD_DIR)/Payment.o $(BUILD_DIR)/RecordesOfServices.o $(BUILD_DIR)/Requests.o $(BUILD_DIR)/Supporter.o $(BUILD_DIR)/User.o
	$(CC) $(CF) $(BUILD_DIR)/main.o $(BUILD_DIR)/Handler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/HealthTourism.o $(BUILD_DIR)/CreditCard.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/FinalBill.o $(BUILD_DIR)/MedicalDocument.o $(BUILD_DIR)/Patient.o $(BUILD_DIR)/Payment.o $(BUILD_DIR)/RecordesOfServices.o $(BUILD_DIR)/Requests.o $(BUILD_DIR)/Supporter.o $(BUILD_DIR)/User.o  -o myserver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
