# Visual Guide: How to Run the Workflow and Select the Branch

## Can't Find the "Run workflow" Button?

Here's what to look for step-by-step:

### Step 1: Go to Actions Tab
1. On your repository page: `https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder`
2. Click the **"Actions"** tab at the top (between "Pull requests" and "Projects")

### Step 2: Find the Workflow
On the left side, you'll see a list of workflows:
- Click on **"Build Marlin (robust patch)"**

### Step 3: Look for "Run workflow" Button
**IMPORTANT**: The "Run workflow" button only appears if you're on the main workflow page.

After clicking "Build Marlin (robust patch)", you should see:
- A list of previous workflow runs in the center
- On the RIGHT side, there should be a **blue button** that says **"Run workflow"**

**If you DON'T see the "Run workflow" button:**
- You might be looking at a specific workflow run (an old build)
- Click "Build Marlin (robust patch)" in the left sidebar again to go back to the main workflow page
- Or click "All workflows" at the top of the left sidebar, then click "Build Marlin (robust patch)"

### Step 4: Click "Run workflow" 
When you click the blue "Run workflow" button:
- A dropdown panel appears
- At the top it says "Use workflow from"
- Below that is a dropdown showing "Branch: main" (or similar)

### Step 5: Select the Branch
1. Click on the "Branch: main" dropdown
2. A list of branches appears
3. Find and click: **"copilot/fix-firmware-issue-ender-3-pro"**
4. The dropdown closes and now shows your selected branch
5. Click the green **"Run workflow"** button that appears below

### Step 6: Wait for Build
- The page refreshes
- A yellow dot appears next to a new workflow run
- Wait 2-3 minutes for it to turn into a green checkmark ✓

### Step 7: Download Firmware
1. Click on the completed workflow run (the one with the green ✓)
2. Scroll to the very bottom of the page
3. Under "Artifacts", click **"firmware-bin"**
4. This downloads a .zip file
5. Extract the .zip to get `firmware.bin`

---

## Still Can't Find It?

The "Run workflow" button only shows if:
1. ✅ You're signed into GitHub (your account)
2. ✅ You have write access to the repository (it's your repo, so you should)
3. ✅ You're on the workflow page (not looking at an individual run)

**Try this:**
1. Go to: `https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/actions/workflows/build.yml`
2. You should see the "Run workflow" button on the right side
3. If you still don't see it, try refreshing the page (F5 or Ctrl+R)

---

## Alternative: I'll Create a Direct Link

If you still can't find it, tell me and I can provide a direct link to trigger the workflow, though you'll still need to select the branch manually.

The direct link format is:
`https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/actions/workflows/build.yml`

When you go there, look for the blue "Run workflow" button on the right side of the page.
