# Central Server

The Central Server acts as the heart of the Distributed GPU Sharing Platform. It is tasked with managing GPU resources, handling user authentication, scheduling tasks, and facilitating communication between Resource Provider Clients (RPCs) and Resource Consumer Clients (RCCs). Below is a detailed design for the Central Server.

## Components of the Central Server:

### Authentication & Authorization Module
**Purpose**: To manage user accounts, authenticate users, and handle permissions via blockchain wallet addresses.

#### Components and Functionalities:
- **User Registration via Wallet Address**: Allows users to register and log in using their blockchain wallet addresses. No traditional username or email is required.
- **Wallet to GPU Binding**: After registration, the wallet address is bound to the user's GPU. This association allows for tracking resource contribution and distribution of rewards.
- **User Authentication**: Validates user's blockchain wallet address during login.
- **Permission Management**: Manages user permissions for resource providers and consumers.

### Resource Manager
**Purpose**: To track and manage the GPU resources provided by Resource Provider Clients (RPCs).

#### Components and Functionalities:
- **Resource Registration**: Allows RPCs to register their GPU resources, including specifications such as processing power, memory, and availability status.
- **Resource Status Monitoring**: Continuously monitors the status of registered GPU resources, checking for availability, utilization rates, and health status.
- **Resource Database**: Maintains a record of all registered GPU resources, including their specifications and statuses.
- **Resource Update**: Allows RPCs to update the status of their resources, such as setting them as available or unavailable for task processing.

### Task Queue Manager
**Purpose**: To manage the queue of tasks submitted by consumers (Resource Consumer Clients - RCCs).

#### Components and Functionalities:
- **Task Submission Interface**: Allows RCCs to submit tasks to be processed, including specifications such as processing requirements and priority.
- **Task Queue**: A queue that holds submitted tasks awaiting allocation of GPU resources.
- **Task Status Update**: Provides updates on task status (e.g., waiting, processing, completed) to RCCs.
- **Task Completion Notification**: Sends notifications to RCCs when their tasks are completed.

### Resource Scheduler
**Purpose**: To allocate available GPU resources to tasks in the task queue based on various factors such as priority and resource availability.

#### Components and Functionalities:
- **Scheduling Algorithm**: Uses scheduling algorithms such as First-Come-First-Serve, Priority Scheduling, or custom algorithms to allocate resources efficiently.
- **Resource Allocation**: Dynamically allocates available GPU resources to tasks in the queue.
- **Task-Resource Mapping**: Keeps track of which resources are allocated to which tasks.
- **Resource Reclamation**: Once a task is completed, the resources are reclaimed and made available for other tasks.

### Communication Module
**Purpose**: To facilitate communication between the Central Server and AI consumers (RCCs) and GPU providers (RPCs).

#### Components and Functionalities:
- **API Endpoints**: Provides RESTful API endpoints for interaction between the Central Server, RCCs, and RPCs (e.g., submitting tasks, registering resources).
- **Data Serialization/Deserialization**: Handles serialization and deserialization of data for communication (e.g., converting task data into JSON format).
- **Authentication**: Ensures that communication is authenticated and authorized.
- **Error Handling & Feedback**: Handles communication errors and provides feedback on the status of requests.

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

