# asteroid2DGameAssessment

[readme.docx](https://github.com/KanekiY/asteroid2DGameAssessment/files/9094287/readme.docx)

<h1> Architecture</h1>

Overall, the engine uses inheritance structure and forms a component system, where it highly decoupled the code from the game instance. The entity class is a combination of different components. Each component builds connections via an event-driven message system.

In addition, an object manager and a level manger are created to manage the instance in game. In this project, the object manager is also an object factory and a message manager. The object manager is initially managed by the level manager, delivering variety of game play.
![gameAssessmentDiagram](https://user-images.githubusercontent.com/62212307/178523671-282cfafe-5f47-4cf8-b776-b3239ebc705e.png)




<h2>Game Object</h2>

Game object is an abstract game object class which is used to create the entity of game object. It contains the common feature of the game object such as ‘update’, ‘component’. It’s the minimal unit of the component management.

<h2>Derived Game Object</h2>

The subclass of the Game Object, it can be added more unique features while keeping the common feature of the base class by overriding functions. One thing to be mentioned is that the project uses component structure, which means a subclass usually be a combination of components. Code is highly decoupled, and thus it’s lack of the cohesion. This will be discussed in the component section.
Component: 
The component is a derived abstract class of the game object class. By doing this way, the component can work safely within the structure of the game object because it inherits the game object.


![image](https://user-images.githubusercontent.com/62212307/178522637-e5997899-2848-4420-a99c-7a6142257323.png)

	Pic 1: an example of derived game object

However, numerous virtual functions may slow down the project. Also, the highly decoupled component causes the low cohesion of the code because each part of code is encapsulated, and variable cannot be accessed easily. To solve this problem, an event-driven message system is used to build communication between components. This will be explained in Object Manager.

<h2>Derived Component:</h2>

In the project, 5 components in total are created. At the construction stage of the component, each component will record the owner game object and the owner game object will also manage the component through a component list.

Each component is highly decoupled with others. For the necessary communication between components, the key component will send a message to the object manager and the message will then be distributed to the target component.

<h2>Object Manager:</h2>

The object manger is a class that manage created in-game entities. Also, to decouple the code and keep high cohesion, the object manager is integrated with the ‘factory’ function and ‘sending message’ function.

<h2>Object Management:</h2>

In Object manager, a list of game object pointer is used to manage the in-game game object. It contains ‘addObject’, ‘updateAll’,’deleteAll’ and ‘delete Inactive’. Because the rendering is encapsulated as a component, there is no render function available in the object manager.

Alternatively, a list of ‘Collision Component pointer’ is used to manage the collision intersection. The collision could be handled inside of the collision component, but in that way, the code will be highly coupled with the object manager. Therefore, creating a collision list while adding object into object list is better.

<h2>Object Factory:</h2>

The object creation is highly coupled with ‘game code’. By creating a factory, the object creation will no longer be coupled with the game code. And the factory is furtherly integrated into the object manager for the convenience of development. Now a new object can be created without new keyword

<h2>Messenger:</h2>

A ‘send msg’ function is used to constantly distribute the event sent by components to other components. In this way, the component build communication with others while being decoupled. Correspondingly, the efficiency of the project may be harmed. 

<h2>Level Manager:</h2>
Level messenger is used to increase the variety of the game play and the environment. It will access the object manager and manage the object in the level. However, due to the given time scale, the level change statement is highly coupled with level manger as it must track statement of the key object.  The unique pointer can be used to solve this problem.

