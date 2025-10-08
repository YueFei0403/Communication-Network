# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2

# Targets (executables)
TARGETS = udp_server udp_client tcp_server tcp_client

# Default rule: build everything
all: $(TARGETS)

# --- UDP Programs ---
udp_server: udp_server.cpp
	$(CXX) $(CXXFLAGS) udp_server.cpp -o udp_server

udp_client: udp_client.cpp
	$(CXX) $(CXXFLAGS) udp_client.cpp -o udp_client

# --- TCP Programs ---
tcp_server: tcp_server.cpp
	$(CXX) $(CXXFLAGS) tcp_server.cpp -o tcp_server

tcp_client: tcp_client.cpp
	$(CXX) $(CXXFLAGS) tcp_client.cpp -o tcp_client

# --- Clean up build artifacts ---
clean:
	rm -f $(TARGETS)
