# Central Server

The Central Server acts as the heart of the Distributed GPU Sharing Platform. It is tasked with managing GPU resources, handling user authentication, scheduling tasks, and facilitating communication between Resource Provider Clients (RPCs) and Resource Consumer Clients (RCCs). Below is detailed design for the Central Server.

## Components of the Central Server:

### Authentication & Authorization Module
**Purpose**: To manage user accounts, authenticate users, and handle permissions via blockchain wallet addresses.

#### Components and Functionalities:
- **User Registration via Wallet Address**: Allows users to register and log in using their blockchain wallet addresses. No traditional username or email is required.
- **Wallet to GPU Binding**: After registration, the wallet address is bound to the user's GPU. This association allows for tracking resource contribution and distribution of rewards.
- **User Authentication**: Validates user's blockchain wallet address during login.
- **Permission Management**: Manages user permissions for resource providers and consumers.

### Resource Manager
**Purpose**: To keep track of available GPU resources from the RPCs.

#### Components and Functionalities:
- **Resource Registration**: Registers GPU resources provided by RPCs along with their specifications.
- **Resource Monitoring**: Continuously monitors the availability and status of registered resources.
- **Resource Database**: Maintains a record of the resources (Consider using a NoSQL database for flexibility and scalability).

### Task Queue Manager
**Purpose**: To manage the queue of tasks submitted by the RCCs.

#### Components and Functionalities:
- **Task Submission**: Allows RCCs to submit tasks to the queue.
- **Task Prioritization**: Prioritizes tasks based on predefined criteria.
- **Task Database**: Maintains records of tasks, their status, and results (SQL or NoSQL).

### Resource Scheduler
**Purpose**: To allocate available GPU resources to tasks in the queue.

#### Components and Functionalities:
- **Scheduling Algorithm**: Implements an algorithm (e.g., Round Robin, Priority Scheduling) to allocate resources efficiently.
- **Resource Allocation**: Assigns tasks to available GPU resources and notifies RPCs.
- **Task Status Tracking**: Tracks the progress of tasks and updates their status in the Task Database.

### Communication Module
**Purpose**: To facilitate communication between the Central Server, RPCs, and RCCs.

#### Components and Functionalities:
- **API Endpoints**: Defines RESTful API endpoints for interaction (e.g., GET /resources, POST /submit_task).
- **Data Serialization**: Handles serialization and deserialization of data (e.g., JSON, Protocol Buffers).
- **Error Handling**: Manages errors and exceptions in communication.

### Database (Storage Layer)
**Purpose**: To store user information, GPU resources data, and tasks data.

#### Components and Functionalities:
- **User Table/Collection**: Stores user credentials and permissions using wallet addresses.
- **Resources Table/Collection**: Stores information about GPU resources.
- **Tasks Table/Collection**: Stores information about tasks, status, and results.

### Security Layer
**Purpose**: To ensure the secure operation of the Central Server.

#### Components and Functionalities:
- **SSL/TLS Encryption**: Encrypts communication channels.
- **Data Encryption**: Encrypts sensitive data in the database.
- **Input Validation**: Prevents SQL injection, XSS, and other malicious input.

### Monitoring & Logging
**Purpose**: To monitor the performance and health of the Central Server.

#### Components and Functionalities:
- **Performance Monitoring**: Monitors CPU, memory usage, and other performance metrics.
- **Error Logging**: Logs errors and exceptions.
- **Alerting**: Sends alerts in case of failures or performance issues.

## Scalability Considerations:
- Design the Central Server for horizontal scalability to handle an increased number of RPCs and RCCs.
- Utilize load balancers to distribute traffic efficiently.
- Implement caching mechanisms to reduce database load.

