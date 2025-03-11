local ui = ysp.lqt.ui
local mainWindow = ui.LWidget(nil)
mainWindow:resize(1920, 1080)
mainWindow:setStyleSheet("background-color: red;")
-- mainWindow:setEnterCallback(function(widget) 
--     DebugMessage("进入了")
-- end
-- )
-- mainWindow:setLeaveCallback(function(widget) 
--     DebugMessage("离开了")
-- end
-- )
local childWindow = ui.LWidget(mainWindow)
local a = mainWindow:width() / 2
local b = mainWindow:height() / 2
DebugMessage("width:",a,"height:",b)
childWindow:setGeometry(10,10,mainWindow:width() / 2,mainWindow:height() / 2)
childWindow:setStyleSheet("background-color: blue;")
childWindow:show()
mainWindow:show()


