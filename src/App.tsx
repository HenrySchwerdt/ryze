import React from 'react';

import CommandPrompt from './components/command/CommandPromt';

const App: React.FC = () => {
  return (
    <div className="h-screen flex items-center justify-center">
      <h1 className="text-4xl font-bold">My Text Editor</h1>
      <CommandPrompt />
    </div>
  );
};

export default App;