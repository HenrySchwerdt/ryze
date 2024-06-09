import React, { useState, useEffect } from 'react';
import {
  Command,
  CommandInput,
  CommandList,
  CommandEmpty,
  CommandGroup,
  CommandItem,
  CommandShortcut,
  CommandSeparator,
} from '@/components/ui/command';

import { HomeIcon, SearchIcon, SettingsIcon, FilePenIcon, CopyIcon, ClipboardPasteIcon, FolderIcon, GitCommitVerticalIcon, CommandIcon } from '../Icons'; // Adjust the import path as necessary

export default function CommandPrompt() {
  const [open, setOpen] = useState(false);

  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      if (event.metaKey && event.key === 'p') {
        event.preventDefault();
        setOpen(true);
      }
    };

    window.addEventListener('keydown', handleKeyDown);

    return () => {
      window.removeEventListener('keydown', handleKeyDown);
    };
  }, []);

  const handleClose = () => {
    setOpen(false);
  };

  return (
    <>
      {open && (
        <div
          className="fixed inset-0 flex items-center justify-center bg-black bg-opacity-50 z-50"
          onClick={handleClose}
        >
          <div
            onClick={(e) => e.stopPropagation()}
          >
            <Command className="rounded-lg border border-gray-200 shadow-md dark:border-gray-800 w-[500px]">
              <CommandInput
                placeholder="Search for a command..."
                className="border-b border-gray-200 dark:border-gray-800 px-4 py-3"
              />
              <CommandList className="p-2">
                <CommandEmpty className="py-6 text-center text-gray-500 dark:text-gray-400">
                  No commands found.
                </CommandEmpty>
                <CommandGroup heading="General">
                  <CommandItem>
                    <HomeIcon className="mr-2 h-5 w-5" />
                    <span>Go to Home</span>
                    <CommandShortcut>⌘H</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <SearchIcon className="mr-2 h-5 w-5" />
                    <span>Search</span>
                    <CommandShortcut>⌘K</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <SettingsIcon className="mr-2 h-5 w-5" />
                    <span>Settings</span>
                    <CommandShortcut>⌘,</CommandShortcut>
                  </CommandItem>
                </CommandGroup>
                <CommandSeparator />
                <CommandGroup heading="Editor">
                  <CommandItem>
                    <FilePenIcon className="mr-2 h-5 w-5" />
                    <span>Edit Document</span>
                    <CommandShortcut>⌘E</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <CopyIcon className="mr-2 h-5 w-5" />
                    <span>Copy</span>
                    <CommandShortcut>⌘C</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <ClipboardPasteIcon className="mr-2 h-5 w-5" />
                    <span>Paste</span>
                    <CommandShortcut>⌘V</CommandShortcut>
                  </CommandItem>
                </CommandGroup>
                <CommandSeparator />
                <CommandGroup heading="Project">
                  <CommandItem>
                    <FolderIcon className="mr-2 h-5 w-5" />
                    <span>Open Project</span>
                    <CommandShortcut>⌘O</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <GitCommitVerticalIcon className="mr-2 h-5 w-5" />
                    <span>Commit Changes</span>
                    <CommandShortcut>⌘G</CommandShortcut>
                  </CommandItem>
                  <CommandItem>
                    <CommandIcon className="mr-2 h-5 w-5" />
                    <span>Deploy to Production</span>
                    <CommandShortcut>⌘D</CommandShortcut>
                  </CommandItem>
                </CommandGroup>
              </CommandList>
            </Command>
          </div>
        </div>
      )}
    </>
  );
}
