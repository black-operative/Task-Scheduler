interface Task {
    Task_Id          : number;
    Task_Description : string;
}

let Task_Id_Counter : number = 0;
let Tasks           : Task[] = [];

const Task_Input      = document.getElementById("task-input") as HTMLInputElement;
const Add_Task_Button = document.getElementById("add-task")   as HTMLButtonElement;
const Task_List       = document.getElementById("task-list")  as HTMLUListElement;

// Adds task to array and then calls render
function Add_Task() : void {
    const Input_Task_Description = Task_Input.value.trim();
    if (Input_Task_Description) {
        const New_Task : Task = {
            Task_Id          : Task_Id_Counter,
            Task_Description : Input_Task_Description
        };

        Task_Id_Counter++;

        Tasks.push(New_Task);
        Render_Tasks();
    }
}
// Deletes task from Task array
function Delete_Task(Target_Task_Id : number) : void {
    // if current task's id doesn't match the designated task id, add to filtered list, assign this new list's value to master list
    Tasks = Tasks.filter(task => task.Task_Id != Target_Task_Id);
    Render_Tasks();
}

// Renders Task array on webpage
function Render_Tasks() : void {
    Task_List.innerHTML    = "";
    Task_List.style.border = Tasks.length !== 0 ? "2px solid black" : "none";
    Tasks.forEach(current_task => {
        const List_Item = document.createElement("li");   

        const Task_Text = document.createElement("span");
        Task_Text.textContent = current_task.Task_Description;
        
        const Delete_Button = document.createElement("button");
        Delete_Button.textContent = "Delete";
        Delete_Button.classList.add("delete-task");
        Delete_Button.onclick = function() { Delete_Task(current_task.Task_Id); }    
    
        List_Item.appendChild(Task_Text);
        List_Item.appendChild(Delete_Button);
        Task_List.appendChild(List_Item);
    });
}

Add_Task_Button.addEventListener(
    "click",
    Add_Task
);

Task_Input.addEventListener(
    "keypress",
    (Event) => {
        if (Event.key === "Enter") {
            Add_Task();
        }
    }
);