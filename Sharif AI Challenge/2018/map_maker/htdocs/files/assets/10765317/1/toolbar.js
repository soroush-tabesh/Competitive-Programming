var Toolbar = pc.createScript('toolbar');

Toolbar.attributes.add('css', {type: 'asset', assetType:'css', title: 'CSS Asset'});
Toolbar.attributes.add('html', {type: 'asset', assetType:'html', title: 'HTML Asset'});
Toolbar.attributes.add('script', {
    type : 'asset',
    assetType : 'script'
});

Toolbar.prototype.initialize = function () {
    // create STYLE element
    var style = document.createElement('style');

    // append to head
    document.head.appendChild(style);
    style.innerHTML = this.css.resource || '';
    
    // Add the HTML
    this.div = document.createElement('div');
    this.div.classList.add('container');
    this.div.innerHTML = this.html.resource || '';
    
    // append to body
    // can be appended somewhere else
    // it is recommended to have some container element
    // to prevent iOS problems of overfloating elements off the screen
    document.body.appendChild(this.div);
    
    this.bindEvents();
};

Toolbar.prototype.bindEvents = function(){
    var app = this.app;
    var models = app.root.findByName('model holder').children;
    var green = this.div.querySelector('#green');
    var earth = this.div.querySelector('#earth');
    var tree  = this.div.querySelector('#tree');
    var rock = this.div.querySelector('#rock');
    //var water = this.div.querySelector('#water');
    var eraser = this.div.querySelector('#eraser');
    var path = this.div.querySelector('#path');
    var camera = this.app.root.findByName('Main Camera');
    
    green.addEventListener('click',function(){
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        app.root.findByName('grass').enabled = true;
        document.body.style.cursor = 'default';
        camera.script.mouseInput.runable = false;
        
        
        app.root.findByName('done').enabled = false;
        var newPath = app.root.findByName('New Path');
        if(newPath !== null && newPath !== undefined){
            newPath.destroy();
        } 
        
    }, false);
    
    earth.addEventListener('click',function(){
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        
        app.root.findByName('dirt').enabled = true;
        document.body.style.cursor = 'default';
        camera.script.mouseInput.runable = false;
        
        app.root.findByName('done').enabled = false;
        var newPath = app.root.findByName('New Path');
        if(newPath !== null && newPath !== undefined){
            newPath.destroy();
        } 
        
    }, false);
    
    tree.addEventListener('click', function() {
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        
        app.root.findByName('tree').enabled = true;
        document.body.style.cursor = 'default';
        camera.script.mouseInput.runable = false;
        
        app.root.findByName('done').enabled = false;
        var newPath = app.root.findByName('New Path');
        if(newPath !== null && newPath !== undefined){
            newPath.destroy();
        } 

    }, false);
    
//     water.addEventListener('click',function(){
//         for(var i = 0; i < models.length; i++) {
//             models[i].enabled = false;
//         }
        
//         app.root.findByName('water').enabled = true;
//         document.body.style.cursor = 'default';
//         camera.script.mouseInput.runable = false;

//     },false);
    
    rock.addEventListener('click',function(){
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        
        app.root.findByName('stone').enabled = true;
        document.body.style.cursor = 'default';
        camera.script.mouseInput.runable = false;
        
        app.root.findByName('done').enabled = false;
        var newPath = app.root.findByName('New Path');
        if(newPath !== null && newPath !== undefined){
            newPath.destroy();
        } 
        
     }, false);
    
    eraser.addEventListener('click',function(){
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        document.body.style.cursor = 'no-drop';
        app.root.findByName('eraser').enabled = true;
        camera.script.mouseInput.runable = false;
        
        
        app.root.findByName('done').enabled = false;
        var newPath = app.root.findByName('New Path');
        if(newPath !== null && newPath !== undefined){
            newPath.destroy();
        } 
        
    },false);
    
    path.addEventListener('click', function() {
        for(var i = 0; i < models.length; i++) {
            models[i].enabled = false;
        }
        app.root.findByName('path').enabled = true;
        app.root.findByName('done').enabled = true;
        
        if(app.root.findByName('New Path') === null || app.root.findByName('New Path') === undefined){
            var newPath = new pc.Entity();
            newPath.name = 'New Path';
            app.root.addChild(newPath);
        }
        
        document.body.style.cursor = 'default';
        camera.script.mouseInput.runable = false;
    }, false);
};
